#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;

        vector<int> vec;
        function<void(int, int)> dfs = [&](int i, int res) -> void {
            if (res == 0) {
                ans.emplace_back(vec);
                return;
            }

            if (res < candidates[i]) { // 边界
                return;
            }

            for (int j = i; j < candidates.size(); ++j) {
                vec.emplace_back(candidates[j]);
                dfs(j, res - candidates[j]);
                vec.pop_back();
            }

            // if (i == candidates.size() || res < candidates[i]) { // 边界
            //     return;
            // }

            // dfs(i + 1, res);

            // vec.emplace_back(candidates[i]);
            // dfs(i, res - candidates[i]);
            // vec.pop_back();
        };

        dfs(0, target);
        return ans;
    }
};