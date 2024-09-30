#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // * 每对元素 & 的结果都为0，即 对应集合交集为空
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int s = 0, j = i;

            // * 倒序枚举
            while (j >= 0 && (s & nums[j]) == 0) {
                s |= nums[j--];
            }

            ans = max(ans, i - j);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums {1, 3, 8, 48, 10};
    cout << sol.longestNiceSubarray(nums);

    return 0;
}