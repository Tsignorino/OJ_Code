#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //* 二分 + 前缀和
        int n = nums.size();
        int ans = 1e9 + 7;
        vector<int> preSum(n + 1);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        for (int i = 1; i <= n; ++i) {
            int s = target + preSum[i - 1];
            auto iter = lower_bound(preSum.begin(), preSum.end(), s);
            if (iter != preSum.end()) {
                ans = min(ans, static_cast<int>(iter - preSum.begin()) - i + 1);
            }
        }

        return ans > n ? 0 : ans;

        //* 滑窗
        // int n = nums.size();
        // int total = 0, ans = 1e9 + 7;
        // for (int l = 0, r = 0; r < n; ++r) {
        //     total += nums[r];

        //     while (total >= target) {
        //         ans = min(ans, r - l + 1);

        //         total -= nums[l];
        //         l++;
        //     }
        // }

        // return ans > n ? 0 : ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << sol.minSubArrayLen(target, nums);

    return 0;
}