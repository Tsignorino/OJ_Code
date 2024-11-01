#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cnt = 0;

        unordered_map<int, int> ump;
        for (int l = 0, r = 0; r < n; ++r) {
            // ump[nums[r]]++;
            // cnt += ump[nums[r]] - 1;
            cnt += ump[nums[r]]++;

            while (cnt >= k) {
                ans += n - r;

                // ump[nums[l]]--;
                // cnt -= ump[nums[l]];
                cnt -= --ump[nums[l]];
                l++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 1, 4, 3, 2, 2, 4};
    int k = 2;
    cout << sol.countGood(nums, k);

    return 0;
}