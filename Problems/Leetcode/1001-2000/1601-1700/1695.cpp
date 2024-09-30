#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // * 求不含重复元素的子数组的最大和
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> cnt; // num, cnt
        for (int l = 0, r = 0; r < n; ++r) {
            cnt[nums[r]]++;
            sum += nums[r];

            while (cnt[nums[r]] != 1) {
                cnt[nums[l]]--;
                sum -= nums[l++];
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << sol.maximumUniqueSubarray(nums);

    return 0;
}