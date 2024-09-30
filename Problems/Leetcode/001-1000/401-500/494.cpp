#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 需要加正号的数的和为 p，那么需要加负号的数和为 s = sum(nums) - p
        // t = p - (s - p)  ==>  p = (s + t) / 2
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target & 1 || target < 0) {
            return 0;
        }
        target /= 2;

        //* 记忆化搜索
        // int n = nums.size();
        // vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        // function<int(int, int)> dfs = [&](int i, int c) -> int {
        //     if (i < 0) {
        //         return c == 0;
        //     }

        //     int& res = memo[i][c];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (c < nums[i]) {
        //         return res = dfs(i - 1, c);
        //     }
        //     return res = dfs(i - 1, c - nums[i]) + dfs(i - 1, c);
        // };

        // return dfs(n - 1, target);

        //* 递推
        // int n = nums.size();
        // vector<vector<int>> f(n + 1, vector<int>(target + 1));
        // f[0][0] = 1;
        // for (int i = 0; i < n; ++i) {
        //     for (int c = 0; c <= target; ++c) {
        //         if (c < nums[i]) {
        //             f[i + 1][c] = f[i][c];
        //         } else {
        //             f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
        //         }
        //     }
        // }
        // return f[n][target];

        // int n = nums.size();
        // vector<vector<int>> f(2, vector<int>(target + 1));
        // f[0][0] = 1;
        // for (int i = 0; i < n; ++i) {
        //     for (int c = 0; c <= target; ++c) {
        //         if (c < nums[i]) {
        //             f[(i + 1) % 2][c] = f[i % 2][c];
        //         } else {
        //             f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
        //         }
        //     }
        // }
        // return f[n % 2][target];

        vector<int> f(target + 1);
        f[0] = 1;
        for (const int& num : nums) {
            for (int c = target; c >= num; --c) {
                f[c] = f[c] + f[c - num];
            }
        }
        return f[target];
    }
};