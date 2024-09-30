#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int key = INT_MIN;

        vector<int> f(n + 1);
        for (int i = 0; i < m; ++i) {
            int pre = f[0];
            for (int j = 0; j < n; ++j) {
                int tmp = f[j + 1];

                int s = nums1[i] * nums2[j];
                key = max(key, s);
                f[j + 1] = ranges::max({f[j + 1], f[j], pre + s});

                pre = tmp;
            }
        }

        return f[n] > 0 ? f[n] : key;
    }
};