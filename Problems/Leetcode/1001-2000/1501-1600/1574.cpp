#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size(), r = n - 1;
        while (r && nums[r - 1] <= nums[r]) {
            r--;
        }
        if (r == 0) {
            return 0;
        }

        int ans = r;
        //* 枚举左端点，移动右端点
        for (int l = 0; l == 0 || nums[l - 1] <= nums[l]; ++l) {
            while (r < n && nums[r] < nums[l]) {
                r++;
            }
            ans = min(ans, r - l - 1);
        }
        return ans;

        //* 枚举右端点，移动左端点
        // int l = 0;
        // while (true) {
        //     while (r == n || nums[l] <= nums[r]) {
        //         ans = min(ans, r - l - 1);

        //         //* 需要删除的是连续子序列
        //         if (nums[l] > nums[l + 1]) {
        //             return ans;
        //         }
        //         l++;
        //     }
        //     r++;
        // }
    }
};

int main() {
    Solution sol;

    vector<int> arr {1, 2, 3, 10, 4, 2, 3, 5};
    cout << sol.findLengthOfShortestSubarray(arr);

    return 0;
}