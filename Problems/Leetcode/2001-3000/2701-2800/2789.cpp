#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        // int n = nums.size();
        // long long ans = 0;
        // for (int i = n - 1; i >= 0; --i) {
        //     long long res = nums[i];
        //     while (i > 0 && res >= nums[i - 1]) {
        //         res += nums[i - 1];
        //         i--;
        //     }

        //     ans = max(ans, res);
        // }
        // return ans;

        //* 简化
        int n = nums.size();
        long long sum = nums.back();
        for (int i = n - 2; i >= 0; --i) {
            sum = nums[i] <= sum ? sum + nums[i] : nums[i];
            // 如果无法合并(nums[i] > sum)，意味着从 nums[i] 开始向左合并可以获得更大的值
        }
        return sum;
    }
};

int main() {
    vector<int> nums {2, 3, 7, 9, 3};

    Solution sol;
    cout << sol.maxArrayValue(nums);

    return 0;
}