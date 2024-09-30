#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * 分组，用哈希表 idxs 记录相同元素的下标
 * 双指针，处理不定长滑窗

    // 基本思路：
    // 等值子数组的元素下标为 idx[l] 到 idx[r]，长度为 idx[r] - idx[l] + 1
    // 其中无需删除的元素的个数为 r - l + 1
    // 则，需要删除的元素个数为 (nums[j] - nums[i]) - (r - l)
 */

// https://leetcode.cn/problems/find-the-longest-equal-subarray/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        vector<vector<int>> idxs(n + 1);
        for (int i = 0; i < n; ++i) {
            // 代码实现时，哈希记录 “至当前位置，需要删除的元素个数”
            idxs[nums[i]].emplace_back(i - idxs[nums[i]].size());
        }

        for (vector<int>& idx : idxs) {
            int m = idx.size();
            if (m <= ans) {
                continue;
            }
            for (int l = 0, r = 0; r < m; ++r) {
                while (idx[r] - idx[l] > k) { // idx[r] - idx[l] 表示窗口需要删除的元素个数
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 3, 2, 3, 1, 3};
    int k = 4;

    sol.longestEqualSubarray(nums, k);

    return 0;
}