#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
    看到这种题就不想写，如果不去看第四题的话，有没有可能写出来呢？
*/

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> result(m, vector<int>(n)), cnt(m, vector<int>(n));

        //* 遍历所有子网格（3 x 3），检查子网格是否符合要求，如果合法，计算子网格平均值
        // 枚举右下角
        for (int i = 2; i < m; ++i) {
            for (int j = 2; j < n; ++j) {
                bool flag = true;

                // 检查左右相邻网格
                for (int x = i - 2; x <= i; ++x) {
                    if (abs(image[x][j - 2] - image[x][j - 1]) > threshold || abs(image[x][j - 1] - image[x][j]) > threshold) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    continue;
                }

                // 检查上下相邻网格
                for (int y = j - 2; y <= j; ++y) {
                    if (abs(image[i - 2][y] - image[i - 1][y]) > threshold || abs(image[i - 1][y] - image[i][y]) > threshold) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    continue;
                }

                // 符合条件，计算平均值
                int avg = 0;
                for (int x = i - 2; x <= i; ++x) {
                    for (int y = j - 2; y <= j; ++y) {
                        avg += image[x][y];
                    }
                }
                avg /= 9;

                // 更新子网格内的 result[i][j]
                // （由于需要计算平均值，先把 avg 加到 result[i][j] 内，再用 cnt 矩阵统计 (i, j) 在多少个合法子网格内）
                for (int x = i - 2; x <= i; ++x) {
                    for (int y = j - 2; y <= j; ++y) {
                        result[x][y] += avg;
                        cnt[x][y]++;
                    }
                }
            }
        }

        //* 如果 cnt[i][j] = 0，则 result[i][j] = image[i][j] ，否则 result[i][j] /= cnt[i][j]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cnt[i][j] == 0) {
                    result[i][j] = image[i][j];
                } else {
                    result[i][j] /= cnt[i][j];
                }
            }
        }

        return result;
    }
};