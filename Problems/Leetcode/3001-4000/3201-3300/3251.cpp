#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 递推式
class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int m = ranges::max(nums);

        vector f(n, vector<long long>(m + 1));
        fill(f[0].begin(), f[0].begin() + nums[0] + 1, 1);

        vector<long long> s(m + 1);
        for (int i = 1; i < n; ++i) {
            partial_sum(f[i - 1].begin(), f[i - 1].end(), s.begin());
            for (int j = 0; j <= nums[i]; ++j) {
                int mx = j + min(nums[i - 1] - nums[i], 0);
                f[i][j] = mx >= 0 ? s[mx] % MOD : 0;
            }
        }

        return accumulate(f[n - 1].begin(), f[n - 1].begin() + nums[n - 1] + 1, 0ll) % MOD;
    }
};

// 优化 1：mx >= 0  <==>  j >= max(nums[i] - nums[i-1], 0)
class Solution2 {
    static constexpr int MOD = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int m = nums.back();

        vector<int> f(m + 1);
        fill(f.begin(), f.begin() + min(m, nums[0]) + 1, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[j] = (f[j] + f[j - 1]) % MOD;
            }

            int j0 = max(nums[i] - nums[i - 1], 0);
            for (int j = min(nums[i], m); j >= j0; --j) { // 空间压缩，倒序更新（同 0-1背包）
                f[j] = f[j - j0];
            }
            fill(f.begin(), f.begin() + min(j0, m + 1), 0);
        }

        return accumulate(f.begin(), f.end(), 0ll) % MOD;
    }
};

// 优化 2：减少前缀和的计算
class Solution3 {
    static constexpr int MOD = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int m = nums.back();

        vector<int> f(m + 1);
        fill(f.begin(), f.begin() + min(m, nums[0]) + 1, 1);

        for (int i = 1; i < n; ++i) {
            int nj = max(nums[i] - nums[i - 1], 0);
            int nm = min(nums[i], m);
            if (nj > nm) {
                return 0;
            }
            for (int j = 1; j <= nm - nj; ++j) {
                f[j] = (f[j] + f[j - 1]) % MOD;
            }
            copy(f.begin(), f.begin() + nm - nj + 1, f.begin() + nj); // 由倒序更新的步骤变化而来
            fill(f.begin(), f.begin() + nj, 0);
        }

        return accumulate(f.begin(), f.end(), 0ll) % MOD;
    }
};

int main() {
    Solution sol;

    return 0;
}