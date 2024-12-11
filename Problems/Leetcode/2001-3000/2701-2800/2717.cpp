#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        auto [a, b] = ranges::minmax_element(nums);
        return a + n - 1 - b - (a > b);
    }
};

/*
Python:

class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        a, b = nums.index(1), nums.index(n)
        return a + n - 1 - b - (a > b)
*/

int main() {
    Solution sol;

    return 0;
}