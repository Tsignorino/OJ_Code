#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int l, int r) -> bool {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (i >= l && i <= r) {
                    continue;
                }
                if (nums[i] > pre) {
                    pre = nums[i];
                } else {
                    return false;
                }
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}