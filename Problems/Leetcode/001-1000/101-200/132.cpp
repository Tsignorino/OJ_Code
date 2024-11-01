#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector g(n, vector<int>(n, 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, n);
        for (int i = 0; i < n; ++i) {
            if (g[0][i]) {
                f[i] = 0;
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (g[j + 1][i]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n - 1];
    }
};

int main() {
    Solution sol;

    return 0;
}