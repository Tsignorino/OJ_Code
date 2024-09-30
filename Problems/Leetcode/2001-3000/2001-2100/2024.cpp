#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();

        function<int(char)> func = [&](char c) -> int {
            int ans = 0, cnt = 0;
            for (int l = 0, r = 0; r < n; ++r) {
                if (s[r] == c && ++cnt > k) {
                    while (s[l] != c) {
                        l++;
                    }
                    l++;
                    cnt--;
                }
                ans = max(ans, r - l + 1);
            }
            return ans;
        };

        return max(func('T'), func('F'));
    }
};

int main() {
    Solution sol;

    string s = "TFFT";
    int k = 1;
    cout << sol.maxConsecutiveAnswers(s, k);

    return 0;
}