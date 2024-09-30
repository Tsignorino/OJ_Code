#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int pre[1001];

int init = []() -> int {
    for (int i = 1; i <= 1000; ++i) {
        string s = to_string(i * i);
        int n = s.size();

        function<bool(int, int)> f = [&](int p, int sum) -> bool {
            if (p == n) {
                return sum == i;
            }

            int x = 0;
            for (int j = p; j < n; ++j) {
                x = x * 10 + s[j] - '0';
                if (f(j + 1, sum + x)) {
                    return true;
                }
            }

            return false;
        };

        pre[i] = pre[i - 1] + (f(0, 0) ? i * i : 0);
    }

    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) { return pre[n]; }
};