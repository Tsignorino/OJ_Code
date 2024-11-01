#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        // unordered_map<int, int> ump;
        // for (int& num : nums) {
        //     ump[num]++;
        // }

        // int ans = 0;
        // for (auto& [v, c] : ump) {
        //     if (c == 2) {
        //         ans ^= v;
        //     }
        // }
        // return ans;

        // int ans = 0;
        // for (int& num : nums) {
        //     ans ^= num;
        // }
        // set<int> set(nums.begin(), nums.end());
        // for (auto& v : set) {
        //     ans ^= v;
        // }
        // return ans;

        // 一次遍历
        int ans = 0;
        long long vis = 0;
        for (int& x : nums) {
            if (vis >> x & 1) {
                ans ^= x;
            } else {
                vis |= 1ll << x;
            }
        }
        return ans;
    }
};

/*
Python:
    return reduce(xor, nums) ^ reduce(xor, set(nums))
*/

int main() {
    Solution sol;

    return 0;
}