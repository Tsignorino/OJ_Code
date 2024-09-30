#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        double ans = 1e9;
        for (int i = 0; i < n / 2; ++i) {
            ans = min(ans, (nums[i] + nums[n - i - 1]) * 1.0 / 2);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}