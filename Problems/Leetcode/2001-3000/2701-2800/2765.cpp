#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        for (int l = 0, r = 1; r < n; ++r) {
            if (nums[r] - nums[l] == (r - l) % 2) { // 判断交替
                ans = max(ans, r - l + 1);
            } else { // l 的移动需要分情况
                if (nums[r] - nums[r - 1] == 1) {
                    l = r - 1;
                    ans = max(ans, 2);
                } else {
                    l = r;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}