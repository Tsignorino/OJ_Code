#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //* 二进制数组 -- 前缀和可以用一个变量维护：1 -> 1，0 -> -1，数量相等 -> 元素和为 0
        unordered_map<int, int> ump {
            {0, -1}
        };
        int ans = 0, cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt--;
            }

            if (ump.contains(cnt)) {
                ans = max(ans, i - ump[cnt]);
            } else {
                ump[cnt] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}