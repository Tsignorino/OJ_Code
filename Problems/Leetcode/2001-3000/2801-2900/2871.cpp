#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0, res = -1;
        for (int& v : nums) {
            res &= v;

            // 如果最后一段与的结果不为 0，则直接合并到上一段，不需要加 1
            if (res == 0) {
                ans++;
                res = -1;
            }
        }
        return max(ans, 1);
    }
};