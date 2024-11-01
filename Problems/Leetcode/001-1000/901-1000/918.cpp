#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = 0;
        int max_f = 0, min_f = 0, sum = 0;
        for (int num : nums) {
            max_f = max(max_f, 0) + num;
            maxSum = max(maxSum, max_f);

            min_f = min(min_f, 0) + num;
            minSum = min(minSum, min_f);

            sum += num;
        }
        return sum == minSum ? maxSum : max(maxSum, sum - minSum);
    }
};