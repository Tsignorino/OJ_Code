#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int trap(vector<int>& height) {
        //* 前后缀分解
        // int n = height.size();
        // vector<int> preMax(n), sufMax(n);

        // preMax[0] = height[0];
        // for (int i = 1; i < n; ++i) {
        //     preMax[i] = max(preMax[i - 1], height[i]);
        // }

        // sufMax[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; --i) {
        //     sufMax[i] = max(sufMax[i + 1], height[i]);
        // }

        // int ans = 0;
        // for (int i = 0; i < n; ++i) {
        //     ans += min(preMax[i], sufMax[i]) - height[i];
        // }

        // return ans;

        //* 双指针
        int n = height.size();
        int l = 0, r = n - 1;
        int preMax = 0, sufMax = 0;
        int ans = 0;
        while (l < r) {
            preMax = max(preMax, height[l]);
            sufMax = max(sufMax, height[r]);
            if (preMax < sufMax) {
                ans += preMax - height[l++];
            } else {
                ans += sufMax - height[r--];
            }
        }
        return ans;
    }
};