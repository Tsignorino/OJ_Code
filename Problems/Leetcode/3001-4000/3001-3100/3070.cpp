#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& matrix, int k) {
        // 二维前缀和
        int m = matrix.size(), n = matrix[0].size();
        int cnt = 0;
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
                cnt += sum[i][j] <= k;
            }
        }

        return cnt;

        //* 赛时
        // vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
        //     }
        // }

        // int cnt = 0;
        // for (int i = 1; i < m + 1; ++i) {
        //     for (int j = 1; j < n + 1; ++j) {
        //         cnt += sum[i][j] <= k;
        //     }
        // }
        // return cnt;
    }
};