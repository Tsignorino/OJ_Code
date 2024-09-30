#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> ump;
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            int v = nums2[i];
            while (!stk.empty() && v >= stk.top()) {
                stk.pop();
            }

            ump[v] = stk.empty() ? -1 : stk.top();

            stk.push(v);
        }

        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            ans[i] = ump[nums1[i]];
        }

        return ans;
    }
};