#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minFlips(vector<vector<int>>& vec) {
        int n = vec.size(), m = vec[0].size();

        int res1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                if (vec[i][j] != vec[i][m - 1 - j]) {
                    res1++;
                }
            }
        }

        int res2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vec[i][j] != vec[n - 1 - i][j]) {
                    res2++;
                }
            }
        }

        return min(res1, res2);
    }
};

int main() {
    Solution sol;

    return 0;
}