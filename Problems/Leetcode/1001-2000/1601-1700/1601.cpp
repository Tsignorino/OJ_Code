#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        int ans = 0, cnt = 0;
        vector<int> status(n);
        function<void(int, int)> f = [&](int i, int cnt) -> void {
            if (i == m) {
                for (int k = 0; k < n; ++k) {
                    if (status[k]) {
                        return;
                    }
                }

                ans = max(ans, cnt);
                return;
            }

            // 选
            status[requests[i][0]]--;
            status[requests[i][1]]++;
            f(i + 1, cnt + 1);

            // 恢复现场
            status[requests[i][0]]++;
            status[requests[i][1]]--;

            // 不选
            f(i + 1, cnt);
        };

        f(0, 0);
        return ans;
    }
};