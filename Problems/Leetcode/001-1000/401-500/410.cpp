#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // l = max(nums) - 1, r = sum(nums) + 1
        int l = *max_element(nums.begin(), nums.end()) - 1;
        int r = accumulate(nums.begin(), nums.end(), 0) + 1;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int cnt = 1, sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += nums[i];

                if (sum > mid) {
                    cnt++;
                    sum = nums[i];
                }
            }

            if (cnt > k) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return r;
    }
};

int main() {
    Solution sol;

    vector<int> nums {7, 2, 5, 10, 8};
    int k = 2;
    cout << sol.splitArray(nums, k);

    return 0;
}