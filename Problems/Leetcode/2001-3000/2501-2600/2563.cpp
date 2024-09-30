#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

            ans += r - l;
        }

        return ans;
    }
};
int main() {
    Solution sol;

    vector<int> nums {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    cout << sol.countFairPairs(nums, lower, upper);

    return 0;
}