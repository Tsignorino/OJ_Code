#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            return 1;
        }

        function<int(int, int, int)> func = [&](int l, int r, int val) -> int { // 闭区间
            if (l >= r) {
                return 0;
            }
            if (l + 1 == r) {
                return nums[l] + nums[r] == val;
            }

            int cnt = 0;
            if (nums[l] + nums[l + 1] == val) {
                cnt = max(cnt, 1 + func(l + 2, r, val));
            }

            return cnt;
        };

        return func(0, n - 1, nums[0] + nums[1]); // 前两个
    }

public:
    int maxOperations_1(vector<int>& nums) {
        int s = nums[0] + nums[1];
        int ans = 1;
        for (int i = 3; i < nums.size() && nums[i - 1] + nums[i] == s; i += 2) {
            ans++;
        }
        return ans;
    }
};
