#include <bits/stdc++.h>

using namespace std;

constexpr int MX = 51;
vector<int> coprime[MX];
auto init = [] {
    for (int i = 1; i < MX; ++i) {
        for (int j = 1; j < MX; ++j) {
            if (gcd(i, j) == 1) {
                coprime[i].emplace_back(j);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (vector<int>& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        vector<int> ans(n, -1);
        vector<pair<int, int>> val_depth_id(MX);
        function<void(int, int, int)> dfs = [&](int x, int pa, int depth) {
            int val = nums[x], max_depth = 0;
            for (int j : coprime[val]) {
                auto [depth, id] = val_depth_id[j];
                if (depth > max_depth) {
                    max_depth = depth;
                    ans[x] = id;
                }
            }

            auto tmp = val_depth_id[val];
            val_depth_id[val] = {depth, x};
            for (int y : g[x]) {
                if (y != pa) {
                    dfs(y, x, depth + 1);
                }
            }
            val_depth_id[val] = tmp;
        };

        dfs(0, -1, 1);
        return ans;
    }
};