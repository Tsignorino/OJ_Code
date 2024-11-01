#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, pair<int, int>> ump;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];

            if (ump.contains(x)) {
                ump[x].second = i; // 更新右端点
            } else {
                ump[x] = {i, i};
            }
        }

        vector<pair<int, int>> vec;
        for (auto& [_, p] : ump) {
            vec.emplace_back(p);
        }
        ranges::sort(vec);

        int ans = 1;
        int mx = vec[0].second;
        for (const auto& [l, r] : vec) {
            if (l > mx) {
                ans = ans * 2 % MOD;
            }
            mx = max(mx, r);
        }
        return ans;
    }
};