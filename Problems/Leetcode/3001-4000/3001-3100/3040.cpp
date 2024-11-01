#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            return 1;
        }

        int memo[n][n];
        auto helper = [&](int i, int j, int val) -> int {
            memset(memo, -1, sizeof(memo));

            function<int(int, int)> func = [&](int l, int r) -> int { // 闭区间
                if (l >= r) {
                    return 0;
                }

                int& res = memo[l][r];
                if (res != -1) {
                    return res;
                }

                res = 0;
                if (nums[l] + nums[l + 1] == val) {
                    res = max(res, 1 + func(l + 2, r));
                }
                if (nums[r] + nums[r - 1] == val) {
                    res = max(res, 1 + func(l, r - 2));
                }
                if (nums[l] + nums[r] == val) {
                    res = max(res, 1 + func(l + 1, r - 1));
                }

                return res;
            };

            return func(i, j);
        };

        int res1 = helper(0, n - 1, nums[0] + nums[1]); // 前两个
        int res2 = helper(0, n - 1, nums[n - 1] + nums[n - 2]); // 后两个
        int res3 = helper(0, n - 1, nums[0] + nums[n - 1]); // 前后各一个
        return max({res1, res2, res3});
    }
};