#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //* 前缀和
        // int n = nums.size();
        // vector<int> preSum(n + 1);
        // int ans = 0, cnt = 0;
        // preSum[0] = 1;
        // for (int i = 0; i < n; ++i) {
        //     cnt += nums[i] & 1;

        //     ans += cnt >= k ? preSum[cnt - k] : 0;
        //     preSum[cnt] += 1;
        // }
        // return ans;

        //* 或者 哈希记录
        // int sum = 0, ans = 0;
        // unordered_map<int, int> ump; // 统计前缀和的出现次数
        // for (const int& num : nums) {
        //     ump[sum]++;

        //     sum += num & 1;
        //     ans += ump[sum - k];
        // }
        // return ans;

        //* 滑窗
        int n = nums.size();
        int ans = 0, cnt1 = 0, cnt2 = 0;
        for (int l1 = 0, l2 = 0, r = 0; r < n; ++r) {
            cnt1 += nums[r] & 1;
            cnt2 += nums[r] & 1;

            // l1 左边都不成立，l1 处成立
            while (l1 <= r && cnt1 > k) {
                cnt1 -= nums[l1++] & 1;
            }

            // l1 与 l2 之间成立，l2 处不成立
            while (l2 <= r && cnt2 >= k) {
                cnt2 -= nums[l2++] & 1;
            }

            ans += l2 - l1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k);

    return 0;
}