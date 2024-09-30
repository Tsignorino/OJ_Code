#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxV = *ranges::max_element(nums);
        vector<int> vec(maxV + 1);
        for (int& num : nums) {
            vec[num] += num;
        }

        int f0 = 0, f1 = 0;
        for (int& v : vec) {
            int tmp = max(f0 + v, f1);

            f0 = f1;
            f1 = tmp;
        }
        return f1;
    }
};