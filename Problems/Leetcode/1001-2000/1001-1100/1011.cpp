#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()) - 1;
        int r = accumulate(nums.begin(), nums.end(), 0) + 1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;

            int cnt = 1, sum = 0;
            for (const int& num : nums) {
                sum += num;
                if (sum > mid) {
                    cnt++;
                    sum = num;
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

    vector<int> weights {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << sol.shipWithinDays(weights, days);

    return 0;
}