#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // f[i][j] 维护以 x 结尾的、包含 j 个不同相邻元素的子序列的最大长度
        // 对于 x：
        // 1. 不选，f[x][j] 不变
        // 2. 选，
        //      1> 和前面一个数 y 一样或者作为子序列的第一个数，f[x][j] += 1
        //      2> 和前面一个数 y 不一样，我们需要知道最大的 f[y][j-1]，以及对应的数字 num
        //          !（本题可暴力枚举）
        //
        //         （维护 f[?][j?1] 中的最大值 mx、最大值对应的数字 num，以及 f[num2][j?1] 中的最大值 mx2，其中 num2 ≠ num）
        //          如果 x != num，那么最大的 f[y][j-1] 就是 mx
        //          如果 x == num，那么最大的 f[y][j-1] 就是 mx2
        //          那么 f[x][j] = max(f[x][j], m) + 1，其中 m 是最大的 f[y][j-1]
        unordered_map<int, vector<int>> memo;
        vector<array<int, 3>> records(k + 1);
        for (int& x : nums) {
            if (!memo.contains(x)) {
                memo[x] = vector<int>(k + 1);
            }

            auto& f = memo[x];
            for (int j = k; j >= 0; --j) {
                f[j]++;
                if (j) {
                    auto& r = records[j - 1];
                    int mx = r[0], mx2 = r[1], num = r[2];
                    f[j] = max(f[j], (x != num ? mx : mx2) + 1);
                }

                int v = f[j];
                auto& p = records[j];
                if (v > p[0]) {
                    if (x != p[2]) {
                        p[2] = x;
                        p[1] = p[0];
                    }
                    p[0] = v;
                } else if (x != p[2] && v > p[1]) {
                    p[1] = v;
                }
            }
        }

        return records[k][0];
    }
};

int main() {
    Solution sol;

    return 0;
}