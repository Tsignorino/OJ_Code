#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, r = *max_element(nums.begin(), nums.end()) + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int cnt = 0;
            for (const int& num : nums) {
                if (num > mid) {
                    cnt += (num - 1) / mid; // 上取整减 1
                }
            }

            if (cnt > maxOperations) {
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

    vector<int> nums {2, 4, 8, 2};
    int maxOperations = 4;
    cout << sol.minimumSize(nums, maxOperations);

    return 0;
}