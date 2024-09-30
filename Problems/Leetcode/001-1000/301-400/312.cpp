#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 区间 DP
        // 假定在 (l, r) 范围内最后剩下的气球为 k，此时的 f[l][r] 由 “以 k 为分割点的两端” 和 “k 本身” 两部分价值组成
        // 枚举区间长度（开区间）
        int n = nums.size();
        vector<int> vec(n + 2, 1);
        copy(nums.begin(), nums.end(), vec.begin() + 1);

        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 3; len <= n + 2; ++len) {
            for (int l = 0, r = l + len - 1; r <= n + 1; ++l, ++r) {
                for (int k = l + 1; k <= r - 1; ++k) {
                    f[l][r] = max(f[l][r], f[l][k] + f[k][r] + vec[l] * vec[k] * vec[r]);
                }
            }
        }
        return f[0][n + 1];
    }
};

int main() {
    Solution sol;

    return 0;
}