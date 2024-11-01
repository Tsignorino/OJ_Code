#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // 枚举切割位置
        // f[i][j] 表示高为 i，宽为 j 的木块能够得到的最多钱数
        // 三种方案：不切、竖着切、横着切
        vector<vector<int>> vec(m + 1, vector<int>(n + 1));
        for (auto& p : prices) {
            vec[p[0]][p[1]] = p[2];
        }

        vector<vector<long long>> f(m + 1, vector<long long>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = vec[i][j];

                //* 小优化
                for (int k = 1; k <= j / 2; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
                }
                for (int k = 1; k <= i / 2; ++k) {
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
                }
            }
        }

        return f[m][n];
    }
};