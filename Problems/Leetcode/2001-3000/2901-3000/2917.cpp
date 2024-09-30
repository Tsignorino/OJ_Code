#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        // int maxV = __popcount(ranges::max(nums));
        vector<int> vals(nums);
        int ans = 0;
        for (int i = 0; i < 31; ++i) { // i <= maxV or i < 31
            int cnt = 0;
            for (int& val : vals) {
                cnt += val & 1;
                val >>= 1;
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};