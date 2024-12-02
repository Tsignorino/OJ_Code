#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> check(n), diag1(2 * n - 1), diag2(2 * n - 1);

        auto dfs = [&](auto&& dfs, int r) {
            if (r == n) {
                ans++;
                return;
            }
            for (int c = 0; c < n; ++c) {
                if (check[c] == 0 && diag1[r + c] == 0 && diag2[r - c + n - 1] == 0) {
                    check[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
                    dfs(dfs, r + 1);
                    check[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
                }
            }
        };
        dfs(dfs, 0);

        return ans;
    }
};