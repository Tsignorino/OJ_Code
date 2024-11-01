#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;

public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll ans = LLONG_MIN, sum = 0;
        map<int, ll> mp;
        for (int v : nums) {
            if (mp.contains(v - k)) {
                ans = max(ans, sum + v - mp[v - k]);
            }
            if (mp.contains(v + k)) {
                ans = max(ans, sum + v - mp[v + k]);
            }

            if (!mp.contains(v) || sum < mp[v]) {
                mp[v] = sum;
            }
            sum += v;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}