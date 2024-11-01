#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        int n = nums1.size();
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = nums1[i] - nums2[i];
        }

        int maxV = 0, minV = 0, pre1 = 0, pre2 = 0;
        for (int& v : vec) {
            pre1 = max(pre1, 0) + v;
            pre2 = min(pre2, 0) + v;

            maxV = max(maxV, pre1);
            minV = min(minV, pre2);
        }

        return max(sum1 - minV, sum2 + maxV);
    }
};