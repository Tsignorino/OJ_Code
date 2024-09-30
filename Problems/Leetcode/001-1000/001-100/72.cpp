#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // 插入一个字符，相当于删除另一个字符串的一个字符
    int minDistance(string s, string t) {
        // int m = s.size(), n = t.size();
        // vector<vector<int>> f(m + 1, vector<int>(n + 1));

        // for (int j = 0; j < n; ++j) {
        //     f[0][j + 1] = j + 1;
        // }

        // for (int i = 0; i < m; ++i) {
        //     f[i + 1][0] = i + 1;
        //     for (int j = 0; j < n; ++j) {
        //         if (s[i] == t[j]) {
        //             f[i + 1][j + 1] = f[i][j];
        //         } else {
        //             f[i + 1][j + 1] = min(f[i][j + 1], min(f[i + 1][j], f[i][j])) + 1;
        //         }
        //     }
        // }

        // return f[m][n];

        int m = s.size(), n = t.size();
        vector<int> f(n + 1);
        iota(f.begin(), f.end(), 0);

        for (int i = 0; i < m; ++i) {
            int pre = f[0]++;
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (s[i] == t[j]) ? pre : min(f[j + 1], min(f[j], pre)) + 1;
                pre = tmp;
            }
        }

        return f[n];
    }
};