#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        int mn = nums[0];
        multiset<int> s {nums.begin() + 2, nums.end()};
        for (int i = 1; i < n - 1; ++i) {
            if (mn < nums[i]) {
                auto iter = s.upper_bound(mn);
                if (iter != s.end() && *iter < nums[i]) {
                    return true;
                }
            }
            mn = min(mn, nums[i]);
            s.extract(nums[i + 1]);
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}