#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxUncrossedLines(vector<int>& s, vector<int>& t) {
        int n = s.size(), m = t.size();
        vector f(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i + 1][j + 1] = s[i] == t[j] ? f[i][j] + 1 : max(f[i + 1][j], f[i][j + 1]);
            }
        }
        return f[n][m];
    }
};

int main() {
    Solution sol;

    return 0;
}