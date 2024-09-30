#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // long long ans = 1;
        // for (int x = n, y = 1; y < m; ++x, ++y) {
        //     ans = ans * x/y;
        // }
        // return ans;

        // long long ans = 1;
        // for (int i = 0; i < min(m - 1, n - 1); ++i) {
        //     ans *= m + n - 2 - i;
        //     ans /= i + 1;
        // }
        // return ans;

        // vector<vector<int>> f(m, vector<int>(n, 1));
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         f[i][j] = f[i - 1][j] + f[i][j - 1];
        //     }
        // }
        // return f[m - 1][n - 1];

        vector<int> f(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};