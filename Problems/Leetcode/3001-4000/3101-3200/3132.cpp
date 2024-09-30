#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2);

        int m = nums1.size(), n = nums2.size();
        // 枚举保留的最小元素
        for (int i = 2;; --i) {
            int diff = nums2[0] - nums1[i];

            for (int k = i, j = 0; k < m; ++k) {
                if (j < n && nums2[j] - nums1[k] == diff && ++j == n) {
                    return diff;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    return 0;
}