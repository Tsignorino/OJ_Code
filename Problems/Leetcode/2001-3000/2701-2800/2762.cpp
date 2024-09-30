#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        multiset<int> set;

        for (int l = 0, r = 0; r < n; ++r) {
            set.emplace(nums[r]);

            while (*set.rbegin() - *set.begin() > 2) {
                set.erase(set.find(nums[l]));
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {5, 4, 2, 4};
    cout << sol.continuousSubarrays(nums);

    return 0;
}