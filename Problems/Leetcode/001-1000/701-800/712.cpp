#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> f(n + 1);
        for (int j = 0; j < n; ++j) {
            f[j + 1] = f[j] + t[j];
        }
        for (int i = 0; i < m; ++i) {
            int pre = f[0];
            f[0] += s[i];
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = s[i] == t[j] ? pre : min(f[j + 1] + s[i], f[j] + t[j]);
                pre = tmp;
            }
        }

        return f[n];
    }
};