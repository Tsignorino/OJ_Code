#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // int l = 0, r = n + 1;
        // while (l + 1 < r) {
        //     int mid = (l + r) / 2;
        //     if (nums[n - mid] >= mid) {
        //         l = mid;
        //     } else {
        //         r = mid;
        //     }
        // }
        // return l;

        int n = nums.size();
        vector<int> cnt(n + 1);
        for (const int& num : nums) { // 引用次数大于 n，等价于 n
            cnt[min(num, n)]++;
        }
        // Example 1:
        // cnt: 1 1 0 1 0 2
        // idx: 0 1 2 3 4 5

        int s = 0;
        for (int i = n;; --i) {
            s += cnt[i];
            if (s >= i) {
                return i;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums {3, 0, 6, 1, 5};
    cout << sol.hIndex(nums);

    return 0;
}