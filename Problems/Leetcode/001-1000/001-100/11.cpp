#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 高度低的线不会与中间的线构成更大面积的容器
        int ans = 0;
        int n = height.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int area = (r - l) * min(height[l], height[r]);
            ans = max(ans, area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};