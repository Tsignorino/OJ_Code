#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 1) {
                continue;
            }

            cnt++;
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
        }

        return nums[n - 3] + nums[n - 2] + nums[n - 1] == 3 ? cnt : -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums {0, 1, 1, 1, 0, 0};
    sol.minOperations(nums);

    return 0;
}