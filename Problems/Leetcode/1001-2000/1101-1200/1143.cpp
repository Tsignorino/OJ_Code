#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // LCS:
    // s[i] == t[j], dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1) + 1)
    // s[i] != t[j], dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1))
    // 因此，dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1), dfs(i-1, j-1) + s[i] == t[j])
    //* 而，s[i] == t[j] 时，需要考虑只选其中一个的情况吗？s[i] != t[j] 时，需要考虑都不选的情况吗？
    // 整理得，
    // s[i] == t[j], dfs(i, j) = dfs(i-1, j-1) + 1;
    // s[i] != t[j], dfs(i, j) = max(dfs(i-1, j), dfs(i, j-1));

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        // vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (text1[i] == text2[j]) {
        //             f[i + 1][j + 1] = f[i][j] + 1;
        //         } else {
        //             f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
        //         }
        //     }
        // }

        // return f[m][n];

        vector<int> f(n + 1);
        for (int i = 0; i < m; ++i) {
            int pre = f[0];
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (text1[i] == text2[j]) ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        }

        return f[n];
    }
};