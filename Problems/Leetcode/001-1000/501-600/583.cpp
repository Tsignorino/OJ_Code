#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // 最长公共子序列 LCS https://leetcode.cn/problems/longest-common-subsequence/
    // 用字符串长度之和减去 LCS 长度的两倍
    int minDistance_0(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        vector<int> f(n + 1);
        for (int i = 0; i < m; ++i) {
            int pre = f[0];
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (text1[i] == text2[j]) ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        }

        return m + n - f[n] * 2;
    }

public:
    // 类似 72 编辑距离 https://leetcode.cn/problems/edit-distance/
    int minDistance_1(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> f(n + 1);
        iota(f.begin(), f.end(), 0);

        for (int i = 0; i < m; ++i) {
            int pre = f[0]++;
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (s[i] == t[j]) ? pre : min(f[j + 1], pre) + 1;
                pre = tmp;
            }
        }

        return f[n];
    }
};