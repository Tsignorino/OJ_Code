#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);

        int i = 0;
        for (int j = (n + 1) / 2; j < n; ++j) {
            if (nums[i] * 2 <= nums[j]) {
                i++;
            }
        }
        return i * 2;

        // auto check = [&](int x) -> bool {
        //     for (int i = 0; i < x; ++i) {
        //         if (nums[i] * 2 > nums[n - x + i]) {
        //             return false;
        //         }
        //     }
        //     return true;
        // };
        //
        // int l = 0, r = n / 2 + 1;
        // while (l + 1 < r) {
        //     int mid = l + (r - l) / 2;
        //
        //     if (check(mid)) {
        //         l = mid;
        //     } else {
        //         r = mid;
        //     }
        // }
        // return l * 2;
    }
};

int main() {
    Solution sol;

    return 0;
}
