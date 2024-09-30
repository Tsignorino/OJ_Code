#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // int maxFrequency(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());

    //     int n = nums.size(), ans = 1;
    //     long long sum = 0, cnt = 0;
    //     for (int l = 0, r = 0; r < n; ++r) {
    //         cnt = 1LL * nums[r] * (r - l) - sum;
    //         sum += nums[r];

    //         while (cnt > k) {
    //             sum -= nums[l];
    //             cnt -= nums[r] - nums[l];
    //             l++;
    //         }

    //         ans = max(ans, r - l + 1);
    //     }

    //     return ans;
    // }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 1;
        long long total = 0;
        for (int l = 0, r = 1; r < n; ++r) {
            total += 1LL * (nums[r] - nums[r - 1]) * (r - l);

            while (total > k) {
                total -= nums[r] - nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 9, 6};
    int k = 2;
    cout << sol.maxFrequency(nums, k);

    return 0;
}