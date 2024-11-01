#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if (m * 1LL * k > n) {
            return -1;
        }

        int l = 0, r = 1e9 + 1;
        // int l = *min_element(nums.begin(), nums.end()) - 1;
        // int r = *max_element(nums.begin(), nums.end()) + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            //* 连续 k 个所有元素不大于 mid 的子数组不重复地出现至少 m 次
            int cnt_k = 0, cnt_m = 0;
            for (int i = 0; i < n && cnt_m < m; ++i) {
                if (nums[i] <= mid) {
                    cnt_k++;

                    if (cnt_k == k) {
                        cnt_m++;
                        cnt_k = 0;
                    }
                } else {
                    cnt_k = 0;
                }
            }

            if (cnt_m < m) {
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

    vector<int> nums {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    int m = 4, k = 2;
    cout << sol.minDays(nums, m, k);

    return 0;
}