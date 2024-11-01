#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxV = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        sum /= 2;
        if (maxV > sum) {
            return false;
        }

        vector<int> f(sum + 1);
        f[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int s = sum; s >= nums[i]; --s) {
                f[s] = f[s] | f[s - nums[i]];
            }
        }

        return f[sum];
    }
};