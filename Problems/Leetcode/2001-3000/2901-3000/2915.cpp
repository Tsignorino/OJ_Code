#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        //* 记忆化搜索
        // int n = nums.size();

        // vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        // function<int(int, int)> dfs = [&](int i, int t) -> int {
        //     if (i < 0) {
        //         return t == 0 ? 0 : INT_MIN;
        //     }

        //     int& res = memo[i][t];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (t < nums[i]) {
        //         return res = dfs(i - 1, t);
        //     }

        //     return res = max(dfs(i - 1, t), dfs(i - 1, t - nums[i]) + 1);
        // };

        // int ans = dfs(n - 1, target);
        // return ans < 0 ? -1 : ans;

        //* 递推
        // int n = nums.size();

        // vector<vector<int>> f(n + 1, vector<int>(target + 1, INT_MIN));
        // f[0][0] = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int t = 0; t <= target; ++t) {
        //         if (t < nums[i]) {
        //             f[i + 1][t] = f[i][t];
        //         } else {
        //             f[i + 1][t] = max(f[i][t], f[i][t - nums[i]] + 1);
        //         }
        //     }
        // }

        // return f[n][target] < 0 ? -1 : f[n][target];

        //* 空间优化
        // int n = nums.size();

        // vector<int> f(target + 1, INT_MIN);
        // f[0] = 0;
        // for (const int& num : nums) {
        //     for (int t = target; t >= num; --t) {
        //         f[t] = max(f[t], f[t - num] + 1);
        //     }
        // }

        // return f[target] < 0 ? -1 : f[target];

        int n = nums.size(), sum = 0;

        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;
        for (const int& num : nums) {
            sum = min(sum + num, target);
            for (int t = sum; t >= num; --t) {
                f[t] = max(f[t], f[t - num] + 1);
            }
        }

        return f[target] < 0 ? -1 : f[target];
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 2, 3, 4, 5};
    int target = 9;
    sol.lengthOfLongestSubsequence(nums, target);

    return 0;
}