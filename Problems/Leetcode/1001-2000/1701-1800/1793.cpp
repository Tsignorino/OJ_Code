#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[k], min_h = nums[k];
        int i = k, j = k;
        for (int p = 0; p < n - 1; ++p) {
            if (j == n - 1 || i && nums[i - 1] > nums[j + 1]) {
                min_h = min(min_h, nums[--i]);
            } else {
                min_h = min(min_h, nums[++j]);
            }

            ans = max(ans, min_h * (j - i + 1));
        }
        return ans;
    }

public:
    int maximumScore_2(vector<int>& nums, int k) {
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
            if (l < k && k < r) {
                ans = max(ans, height * (r - l - 1));
            }
        }

        return ans;
    }
};