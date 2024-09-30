#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n, vector<int>());
        for (int i = 1; i < n; ++i) {
            g[parent[i]].emplace_back(i);
        }

        int ans = 0;
        function<int(int)> dfs = [&](int x) -> int {
            int maxLen = 0;
            for (const int& y : g[x]) {
                int yLen = dfs(y) + 1;

                if (s[x] != s[y]) {
                    ans = max(ans, maxLen + yLen);
                    maxLen = max(maxLen, yLen);
                }
            }
            return maxLen;
        };

        dfs(0);
        return ans + 1;
    }
};