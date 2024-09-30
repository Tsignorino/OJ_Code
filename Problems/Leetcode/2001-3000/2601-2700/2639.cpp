#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int maxV = INT_MIN, minV = INT_MAX;
            for (int j = 0; j < m; ++j) {
                maxV = max(maxV, grid[j][i]);
                minV = min(minV, grid[j][i]);
            }
            
            // ans[i] = max(to_string(maxV).size(), to_string(minV).size());
            int len = 1;
            for (int x = max(maxV / 10, -minV); x; x /= 10) {
                len++;
            }
            ans[i] = len;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}