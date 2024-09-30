#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> nums(26);
        iota(nums.begin(), nums.end(), 1);
        for (int i = 0; i < chars.size(); ++i) {
            nums[chars[i] - 'a'] = vals[i];
        }

        int ans = 0;
        int f = 0;
        for (char ch : s) {
            f = max(f, 0) + nums[ch - 'a'];
            ans = max(ans, f);
        }
        return ans;
    }
};