#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            cnt += 1 - nums[r];
            while (cnt > k) {
                cnt -= 1 - nums[l++];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << sol.longestOnes(nums, k);

    return 0;
}