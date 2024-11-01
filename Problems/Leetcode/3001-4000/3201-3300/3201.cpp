#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int func(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> f(k);
            for (int num : nums) {
                num %= k;
                f[num] = max(f[num], f[(i - num + k) % k] + 1);
            }
            ans = max(ans, ranges::max(f));
        }
        return ans;
    }

public:
    int maximumLength(vector<int>& nums) { return func(nums, 2); }
};

int main() {
    Solution sol;

    return 0;
}