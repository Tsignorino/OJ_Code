#include <bits/stdc++.h>

using namespace std;

using ll = long long;
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        ll ans = nums.size();
        stack<pair<int, int>> stk;
        stk.emplace(INT_MAX, 0);
        for (int num : nums) {
            while (num > stk.top().first) {
                stk.pop();
            }

            if (num == stk.top().first) {
                ans += stk.top().second++;
            } else {
                stk.emplace(num, 1);
            }
        }
        return ans;
    }
};

// 2421