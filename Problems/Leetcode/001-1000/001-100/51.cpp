#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n), check(n), diag1(2 * n - 1), diag2(2 * n - 1);

        function<void(int)> dfs = [&](int r) -> void {
            if (r == n) {
                vector<string> str(n);
                for (int i = 0; i < n; ++i) {
                    str[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
                }
                ans.emplace_back(str);
                return;
            }

            for (int c = 0; c < n; ++c) {
                if (check[c] == 0 && diag1[r + c] == 0 && diag2[r - c + n - 1] == 0) {
                    col[r] = c;
                    check[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;
                    dfs(r + 1);
                    check[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
                }
            }
        };

        dfs(0);
        return ans;
    }
};