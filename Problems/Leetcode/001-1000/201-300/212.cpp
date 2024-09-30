#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int func(vector<int>& nums, int l, int r) {
        int f0 = 0, f1 = 0;

        for (int i = l; i < r; ++i) {
            int f2 = max(f1, f0 + nums[i]);

            f0 = f1;
            f1 = f2;
        }

        return f1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + func(nums, 2, n - 1), func(nums, 1, n));
    }
};