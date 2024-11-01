#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // * 同 1423

    // 逆向思维
    // int minOperations(vector<int>& nums, int x) {
    //     int ans = -1, n = nums.size();

    //     int total = accumulate(nums.begin(), nums.end(), 0) - x;
    //     if (total < 0) {
    //         return -1;
    //     }
    //     if (total == 0) {
    //         return n;
    //     }

    //     for (int l = 0, r = 0, sum = 0; r < n; ++r) {
    //         sum += nums[r];

    //         while (sum > total) {
    //             sum -= nums[l++];
    //         }

    //         if (sum == total) {
    //             ans = max(ans, r - l + 1);
    //         }
    //     }

    //     return ans == -1 ? -1 : n - ans;
    // }

    // 正向思维
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, r = n;

        // 计算最长后缀
        while (r > 0 && sum + nums[r - 1] <= x) {
            sum += nums[--r];
        }

        if (r == 0 && sum < x) { // 全部移除也不能满足要求
            return -1;
        }

        int ans = sum == x ? n - r : n + 1;
        for (int l = 0; l < n; ++l) {
            sum += nums[l];

            while (r < n && sum > x) { // 减小后缀
                sum -= nums[r++];
            }

            if (sum > x) { // 前缀过大
                break;
            }

            if (sum == x) {
                ans = min(ans, l + 1 + n - r);
            }
        }

        return ans > n ? -1 : ans;
    }
};

int main() {
    Solution sol;

    // vector<int> nums {1, 1};
    // int x = 3;

    vector<int> nums {8828, 9581, 49, 9818, 9974, 9869, 9991, 10000, 10000, 10000, 9999, 9993, 9904, 8819, 1231, 6309};
    int x = 134365;
    cout << sol.minOperations(nums, x);

    return 0;
}