#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isInterleave_0(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) {
            return false;
        }

        vector memo(n1 + 1, vector<int>(n2 + 1, -1));

        // dfs(i, j) 表示 s1 的前 i 个和 s2 的前 j 个字符是否和 s3 的前 i+j 个字符匹配
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i < 0) {
                return s2.substr(0, j + 1) == s3.substr(0, j + 1);
            }
            if (j < 0) {
                return s1.substr(0, i + 1) == s3.substr(0, i + 1);
            }

            int& res = memo[i][j];
            if (res != -1) {
                return res;
            }

            bool flag = false;
            if (s1[i] == s3[i + j + 1]) {
                flag |= dfs(i - 1, j);
            }
            if (s2[j] == s3[i + j + 1]) {
                flag |= dfs(i, j - 1);
            }

            return res = flag;
        };

        return dfs(n1 - 1, n2 - 1);
    }

public:
    bool isInterleave_1(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) {
            return false;
        }

        vector<int> f(n2 + 1);
        f[0] = 1;
        for (int j = 0; j < n2; ++j) {
            f[j + 1] = f[j] & (s2[j] == s3[j]);
        }

        for (int i = 0; i < n1; ++i) {
            f[0] = f[0] & (s1[i] == s3[i]);
            for (int j = 0; j < n2; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = false;

                if (s1[i] == s3[i + j + 1]) {
                    f[j + 1] |= tmp;
                }
                if (s2[j] == s3[i + j + 1]) {
                    f[j + 1] |= f[j];
                }
            }
        }

        return f[n2];
    }
};