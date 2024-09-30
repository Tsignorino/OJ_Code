#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray_1(vector<int>& nums) {
        // dp: f[i] 表示以 a[i] 结尾的最大子数组和
        int pre = 0;
        int ans = nums[0];
        for (int num : nums) {
            pre = max(pre, 0) + num;
            ans = max(ans, pre);
        }
        return ans;
    }

public:
    int maxSubArray_2(vector<int>& nums) {
        // greedy
        int ans = INT_MIN;
        int sum = 0;
        for (int& num : nums) {
            if (sum < 0) {
                sum = 0;
            }

            sum += num;
            ans = max(ans, sum);
        }
        return ans;
    }

public:
    int maxSubArray_3(vector<int>& nums) {
        // preSum
        int ans = INT_MIN;
        int min_preSum = 0;
        int preSum = 0;
        for (int num : nums) {
            preSum += num;
            ans = max(ans, preSum - min_preSum);
            min_preSum = min(min_preSum, preSum);
        }
        return ans;
    }

public:
    struct Status {
        int lsum, rsum, maxSum, sum;
    };

    Status pushup(Status left, Status right) {
        int sum = left.sum + right.sum;
        int lsum = max(left.lsum, left.sum + right.lsum);
        int rsum = max(right.rsum, right.sum + left.rsum);
        int maxSum = max({left.maxSum, right.maxSum, left.rsum + right.lsum});
        return Status(lsum, rsum, maxSum, sum);
    }

    Status get(vector<int>& vec, int l, int r) {
        if (l == r) {
            return Status(vec[l], vec[l], vec[l], vec[l]);
        }

        int mid = l + (r - l) / 2;
        Status left = get(vec, l, mid);
        Status right = get(vec, mid + 1, r);
        return pushup(left, right);
    }

    int maxSubArray(vector<int>& nums) {
        // 分治
        return get(nums, 0, nums.size() - 1).maxSum;
    }
};