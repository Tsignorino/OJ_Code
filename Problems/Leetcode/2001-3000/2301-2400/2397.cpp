#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();

        // 将 matrix 每行压缩成二进制数
        vector<int> mask(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mask[i] |= matrix[i][j] << j;
            }
        }

        int ans = 0;
        // for (int subset = 0; subset < (1 << n); ++subset) {
        //     // 选择 numSelect 的情况
        //     if (__popcount(subset) == numSelect) {
        //         int covered = 0;
        //         for (const int& row : mask) {
        //             covered += (row & subset) == row;
        //         }
        //         ans = max(ans, covered);
        //     }
        // }

        //* 上述枚举有很多无效的情况，利用 Gosper's Hack 可以在 O(1) 的时间内构造下一个 subset
        int subset = (1 << numSelect) - 1;
        while (subset < (1 << n)) {
            int covered = 0;
            for (const int& row : mask) {
                covered += (row & subset) == row;
            }
            ans = max(ans, covered);

            int lowbit = subset & -subset;

            int x = subset + lowbit; // 左半部分
            subset = ((subset ^ x) / lowbit >> 2) | x; // 右半部分 | 左半部分
        }

        return ans;
    }
};