#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // 子数组和的绝对值的最大值 <==> 最大子数组的和 或者 最小子数组和的相反数
        int ans = 0;
        int max_f = 0, min_f = 0;
        for (int num : nums) {
            max_f = max(max_f, 0) + num;
            min_f = min(min_f, 0) + num;
            ans = max(ans, max(max_f, -min_f));
        }
        return ans;
    }

    int maxAbsoluteSum_1(vector<int>& nums) {
        int sum = 0, maxV = 0, minV = 0;
        for (int num : nums) {
            sum += num;
            maxV = max(maxV, sum);
            minV = min(minV, sum);
        }
        return maxV - minV;
    }
};