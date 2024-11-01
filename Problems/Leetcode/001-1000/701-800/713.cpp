#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if (k <= 1) {
        //     return 0;
        // }
        int n = nums.size(), mul = 1, ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            mul *= nums[r];

            while (l <= r && mul >= k) { //* 特判的话就不需要 l <= r 了
                mul /= nums[l++];
            }

            ans += r - l + 1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {10, 5, 2, 6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k);

    return 0;
}