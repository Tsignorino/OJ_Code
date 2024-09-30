#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minFlips(vector<vector<int>>& vec) {
        int n = vec.size(), m = vec[0].size();

        int res = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int tot = vec[i][j] + vec[i][m - 1 - j] + vec[n - 1 - i][j] + vec[n - 1 - i][m - 1 - j];
                res += min(tot, 4 - tot);
            }
        }

        if (n & 1 && m & 1) { // 中间必须是 0
            res += vec[n / 2][m / 2];
        }

        int diff = 0; // 失配对数
        int cnt = 0;
        if (n & 1) {
            for (int i = 0; i < m / 2; ++i) {
                if (vec[n / 2][i] != vec[n / 2][m - 1 - i]) {
                    diff++;
                } else {
                    cnt += vec[n / 2][i];
                }
            }
        }
        if (m & 1) {
            for (int i = 0; i < n / 2; ++i) {
                if (vec[i][m / 2] != vec[n - 1 - i][m / 2]) {
                    diff++;
                } else {
                    cnt += vec[i][m / 2];
                }
            }
        }

        int ans = res + diff;
        if (cnt * 2 % 4 && diff == 0) {
            ans += 2;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}