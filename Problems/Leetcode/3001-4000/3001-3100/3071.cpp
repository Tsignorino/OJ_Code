#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt1[3] {}, cnt2[3] {};
        for (int i = 0; i < n / 2; ++i) {
            cnt1[grid[i][i]]++;
            cnt1[grid[i][n - i - 1]]++;
        }
        for (int i = n / 2; i < n; ++i) {
            cnt1[grid[i][n / 2]]++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt2[grid[i][j]]++;
            }
        }

        int maxV = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    continue;
                }
                maxV = max(maxV, cnt1[i] + cnt2[j] - cnt1[j]);
            }
        }
        return n * n - maxV;
    }
};