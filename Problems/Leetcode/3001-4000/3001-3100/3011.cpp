#include <bits/stdc++.h>

using namespace std;

/*
    分组循环
*/

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n;) {
            int start = i;
            int ones = __builtin_popcount(nums[i++]);
            while (i < n && __builtin_popcount(nums[i]) == ones) {
                i++;
            }
            sort(nums.begin() + start, nums.begin() + i);
        }
        return ranges::is_sorted(nums);
    }

    bool canSortArray_(vector<int>& nums) {
        int n = nums.size();
        int preMax = 0;
        for (int i = 0; i < n;) {
            int mx = 0;
            int ones = __builtin_popcount(nums[i]);
            while (i < n && __builtin_popcount(nums[i]) == ones) {
                if (nums[i] < preMax) {
                    return false;
                }
                mx = max(mx, nums[i++]);
            }
            preMax = mx;
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}