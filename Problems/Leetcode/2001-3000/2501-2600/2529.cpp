#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCount_1(vector<int>& nums) {
        int n = ranges::lower_bound(nums, 0) - nums.begin();
        int m = nums.end() - ranges::upper_bound(nums, 0);
        return max(n, m);
    }

public:
    int maximumCount(vector<int>& nums) {
        auto [l_iter, r_iter] = ranges::equal_range(nums, 0);
        return max(l_iter - nums.begin(), nums.end() - r_iter);
    }
};