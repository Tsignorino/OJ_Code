#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector f(n, vector<int>(m, INT_MAX / 2));
        f[n - 1][m - 1] = max(1, 1 - g[n - 1][m - 1]); // !
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i > 0) {
                    f[i - 1][j] = max(1, min(f[i - 1][j], f[i][j] - g[i - 1][j]));
                }
                if (j > 0) {
                    f[i][j - 1] = max(1, min(f[i][j - 1], f[i][j] - g[i][j - 1]));
                }
            }
        }
        return f[0][0];
    }
};

int main() {
    Solution sol;

    return 0;
}