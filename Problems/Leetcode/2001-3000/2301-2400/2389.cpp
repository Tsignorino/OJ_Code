#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        ranges::sort(nums);

        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        vector<int> ans;
        for (int q : queries) {
            ans.emplace_back(ranges::upper_bound(pre, q) - pre.begin() - 1);
        }
        return ans;
    }
};