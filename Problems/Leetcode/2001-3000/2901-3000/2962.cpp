#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // long long countSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int max_v = *max_element(nums.begin(), nums.end());

    //     ll ans = 0;
    //     for (int l = 0, r = 0; r < n; ++r) {
    //         k -= nums[r] == max_v;

    //         while (k == 0) {
    //             k += nums[l] == max_v;

    //             l++;
    //         }

    //         ans += l;
    //     }

    //     return ans;
    // }

    long long countSubarrays(vector<int>& nums, int k) {
        int max_v = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int l = 0;
        for (const int& x : nums) {
            k -= x == max_v;

            while (k == 0) {
                k += nums[l++] == max_v;
            }

            ans += l;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 3, 2, 3, 3};
    int k = 2;
    sol.countSubarrays(nums, k);

    return 0;
}