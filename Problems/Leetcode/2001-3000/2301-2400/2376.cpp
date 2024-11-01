#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();

        // 通过判断 mask 是否为 0 去掉 isNum 参数
        vector memo(m, vector<int>(1 << 10, -1));
        auto dfs = [&](auto&& dfs, int i, int mask, bool isLimit) -> int {
            if (i == m) {
                return mask != 0;
            }

            if (!isLimit && mask && memo[i][mask] != -1) {
                return memo[i][mask];
            }

            int res = 0;
            if (mask == 0) { // 可以跳过当前位
                res = dfs(dfs, i + 1, mask, false);
            }

            int up = isLimit ? s[i] - '0' : 9;
            for (int k = mask ? 0 : 1; k <= up; ++k) {
                if (mask >> k & 1) {
                    continue;
                }
                res += dfs(dfs, i + 1, mask | (1 << k), isLimit && k == up);
            }

            if (!isLimit && mask) {
                memo[i][mask] = res;
            }
            return res;
        };

        return dfs(dfs, 0, 0, true);
    }
};

int main() {
    Solution sol;

    return 0;
}