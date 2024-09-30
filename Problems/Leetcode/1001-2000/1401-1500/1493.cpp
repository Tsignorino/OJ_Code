#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, l = 0, r = 0;
        while (r < n) {
            sum += nums[r];

            if (sum < r - l) {
                sum -= nums[l++];
            }

            r++;
        }
        
        return r - l - 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 1, 0, 1};
    cout << sol.longestSubarray(nums);

    return 0;
}