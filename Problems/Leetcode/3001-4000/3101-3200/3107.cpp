#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size(), m = n / 2;
        ranges::nth_element(nums, nums.begin() + m);
        long long ans = 0;
        if (nums[m] > k) {
            for (int i = 0; i <= m; ++i) {
                ans += max(nums[i] - k, 0);
            }
        } else {
            for (int i = m; i < n; ++i) {
                ans += max(k - nums[i], 0);
            }
        }
        return ans;
    }

public:
    long long my_minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int val = nums[n / 2];
        long long ans = 0;

        if (k < val) {
            for (int i = n / 2; i >= 0 && nums[i] > k; --i) {
                ans += nums[i] - k;
            }
        } else {
            for (int i = n / 2; i < n && nums[i] < k; ++i) {
                ans += k - nums[i];
            }
        }
        return ans;
    }
};