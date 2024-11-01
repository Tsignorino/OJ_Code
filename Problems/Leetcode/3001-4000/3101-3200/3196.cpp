#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

/*
    状态机 DP
*/

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        /*
            记忆化搜索
        */
        // int n = nums.size();
        // vector<array<long long, 2>> memo(n, {LLONG_MIN, LLONG_MIN});
        // auto dfs = [&](auto&& dfs, int i, int ok) -> long long {
        //     if (i == n) {
        //         return 0;
        //     }

        //     auto& res = memo[i][ok];
        //     if (res != LLONG_MIN) {
        //         return res;
        //     }

        //     return res = max(dfs(dfs, i + 1, ok) + nums[i], dfs(dfs, i + 1, ok ^ 1) + (ok == 0 ? nums[i] : -nums[i]));
        // };
        // return dfs(dfs, 0, 0);

        /*
            递推
        */
        // int n = nums.size();
        // vector f(n, vector<long long>(2, LLONG_MIN / 2));
        // f[0][0] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     f[i][0] = max(f[i - 1][0], f[i - 1][1]) + nums[i];
        //     f[i][1] = f[i - 1][0] - nums[i];
        // }
        // return ranges::max(f.back());

        /*
            空间优化
        */
        long long f0 = 0, f1 = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            long long new_f0 = f1 + nums[i];
            f1 = max(f1 + nums[i], f0 - nums[i]);
            f0 = new_f0;
        }
        return f0;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, -2, 3, 4};
    cout << sol.maximumTotalCost(nums);

    return 0;
}