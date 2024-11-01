#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                stk.pop();
            }

            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.emplace(i);
        }

        vector<int> right(n, n);
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                stk.pop();
            }

            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.emplace(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) { // 开区间
            int height = nums[i], l = left[i], r = right[i];
            ans = max(ans, height * (r - l - 1));
        }

        return ans;
    }
};