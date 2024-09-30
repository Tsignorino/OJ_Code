#include <bits/stdc++.h>

using namespace std;

/*
    连续区间分组 （×）
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int ans = 0;

        // 假定修改后的连续数组值域为 [x-n+1, x]
        for (int l = 0, r = 0; r < m; ++r) {
            while (nums[l] < nums[r] - n + 1) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return n - ans;
    }
};

int main() {
    vector<int> nums {1, 2, 3, 1000};

    Solution sol;
    cout << sol.minOperations(nums);

    return 0;
}