#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxV = 1, minV = 1;
        for (int& v : nums) {
            int v1 = maxV, v2 = minV;

            maxV = max(v1 * v, max(v, v2 * v));
            minV = min(v2 * v, min(v, v1 * v));
            ans = max(ans, maxV);
        }
        return ans;
    }
};