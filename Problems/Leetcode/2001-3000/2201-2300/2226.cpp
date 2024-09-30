#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        int r = 1e7 + 1;
        // int r = *max_element(nums.begin(), nums.end()) + 1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;

            long long cnt = 0;
            for (const int& num : nums) {
                cnt += num / mid;
            }

            if (cnt >= k) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

int main() {
    Solution sol;

    vector<int> candies {5, 8, 6};
    int k = 3;
    cout << sol.maximumCandies(candies, k);

    return 0;
}