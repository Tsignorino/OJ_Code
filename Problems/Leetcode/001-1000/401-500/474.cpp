#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> c(len);
        for (int i = 0; i < len; ++i) {
            int c0 = count(strs[i].begin(), strs[i].end(), '0');
            int c1 = strs[i].size() - c0;
            c[i] = pair(c0, c1);
        }

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 0; i < len; ++i) {
            auto& [c0, c1] = c[i];
            for (int j = m; j >= c0; --j) {
                for (int k = n; k >= c1; --k) {
                    f[j][k] = max(f[j][k], f[j - c0][k - c1] + 1);
                }
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution sol;

    return 0;
}