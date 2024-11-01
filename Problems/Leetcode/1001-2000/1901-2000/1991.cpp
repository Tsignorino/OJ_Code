#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int ls = 0;
        for (int i = 0; i < n; ++i) {
            if (ls * 2 == s - nums[i]) {
                return i;
            }
            ls += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;


    return 0;
}