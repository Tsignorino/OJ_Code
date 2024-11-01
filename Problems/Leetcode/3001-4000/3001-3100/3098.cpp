#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        ranges::sort(nums);

        int ans = 0;
        map<vector<int>, int> mp;
        function<int(int, int, int, int)> dfs = [&](int i, int cnt, int pre, int min_diff) -> int {
            if (mp.contains(vector<int> {cnt, pre, min_diff})) {
                return mp[vector<int> {cnt, pre, min_diff}];
            }

            if (cnt > i + 1) {
                return 0;
            }
            if (cnt == 0) {
                return min_diff;
            }

            int res1 = dfs(i - 1, cnt, pre, min_diff);
            int res2 = dfs(i - 1, cnt - 1, nums[i], min(min_diff, abs(pre - nums[i])));
            return mp[vector<int> {cnt, pre, min_diff}] = (res1 + res2) % mod;
        };

        return dfs(n - 1, k, INT_MAX / 2, INT_MAX / 2);
    }
};