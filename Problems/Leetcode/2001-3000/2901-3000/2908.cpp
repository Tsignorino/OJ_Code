#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            pre[i] = min(pre[i - 1], nums[i]);
        }

        int ans = INT_MAX;
        int suf = nums[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            if (pre[i - 1] < nums[i] && nums[i] > suf) {
                ans = min(ans, pre[i - 1] + nums[i] + suf);
            }
            suf = min(suf, nums[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};