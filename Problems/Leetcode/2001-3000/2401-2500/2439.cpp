#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        //* 二分
        // int n = nums.size();
        // int l = -1, r = *max_element(nums.begin(), nums.end()) + 1;
        // while (l + 1 < r) {
        //     int mid = l + (r - l) / 2;

        //     // nums[i - 1] += max(nums[i] - mid, 0);
        //     long long vec = nums[n - 1];
        //     for (int i = n - 1; i > 0; --i) {
        //         vec = nums[i - 1] + max(vec - mid, 0LL);
        //     }

        //     if (vec > mid) {
        //         l = mid;
        //     } else {
        //         r = mid;
        //     }
        // }
        // return r;

        //* 分类讨论
        // 数组中只有 nums[0]，最大值为 nums[0]
        // 数组中再添加 nums[1]，如果 nums[1] 不大于之前的最大值，则最大值保持不变，
        // 否则最大值为平均值上取整。
        // 数组中再添加 nums[2]，如果 nums[2] 不大于之前的最大值，
        // 也就是说，三个数平均值不超过之前的最大值，
        // 那么最大值保持不变，否则平均这三个值
        long long s = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            ans = max(ans, (s + i) / (i + 1));
            // 注意：
            // (s - 1) / (i + 1) + 1
            // (s + i) / (i + 1)
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 7, 1, 6};
    cout << sol.minimizeArrayValue(nums);

    return 0;
}