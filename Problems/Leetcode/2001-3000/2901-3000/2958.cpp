#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> ump;
        for (int l = 0, r = 0; r < n; ++r) {
            ump[nums[r]]++;

            while (ump[nums[r]] > k) {
                ump[nums[l++]]--;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    cout << sol.maxSubarrayLength(nums, k);

    return 0;
}