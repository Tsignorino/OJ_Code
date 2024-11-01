#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        // f[i+1] 表示能否有效划分 nums[0] ~ nums[i]
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (f[i - 1] && nums[i] == nums[i - 1] || i > 1 && f[i - 2] && (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] || nums[i] - 1 == nums[i - 1] && nums[i - 1] - 1 == nums[i - 2])) {
                f[i + 1] = 1;
            }
        }
        return f[n];
    }
};

int main() {
    vector<int> nums {803201, 803201, 803202, 803203};
    Solution sol;
    cout << sol.validPartition(nums);

    return 0;
}