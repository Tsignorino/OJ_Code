#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //* 前缀和 + 哈希
        // int sum = 0, ans = 0;
        // unordered_map<int, int> ump; // 统计前缀和的出现次数
        // for (const int& num : nums) {
        //     ump[sum]++;

        //     sum += num;
        //     ans += ump[sum - goal];
        // }
        // return ans;

        //* 滑窗
        int n = nums.size(), ans = 0;
        int sum1 = 0, sum2 = 0;

        for (int l1 = 0, l2 = 0, r = 0; r < n; ++r) {
            sum1 += nums[r];
            sum2 += nums[r];

            // l1 左边的不满足条件，l1 与 l2 之间的满足条件
            // l1 处满足条件，l2 处不满足条件
            while (l1 <= r && sum1 > goal) {
                sum1 -= nums[l1++];
            }
            while (l2 <= r && sum2 >= goal) {
                sum2 -= nums[l2++];
            }

            ans += l2 - l1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 0, 1, 0, 1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal);

    return 0;
}