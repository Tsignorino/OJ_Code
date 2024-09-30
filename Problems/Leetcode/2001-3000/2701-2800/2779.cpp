#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);

        int ans = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}