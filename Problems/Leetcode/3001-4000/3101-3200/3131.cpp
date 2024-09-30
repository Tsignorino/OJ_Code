#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        // ranges::sort(nums1);
        // ranges::sort(nums2);
        // return nums2[0] - nums1[0];
        return ranges::min(nums2) - ranges::min(nums1);
    }
};

int main() {
    Solution sol;

    return 0;
}