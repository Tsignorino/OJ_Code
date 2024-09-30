#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int findIntegers(int n) {
        int m = __lg(n);

        vector<array<int, 2>> memo(m + 1, {-1, -1});
        function<int(int, bool, bool)> dfs = [&](int i, bool pre, bool isLimit) -> int {
            if (i < 0) {
                return 1;
            }
            if (!isLimit && memo[i][pre] >= 0) {
                return memo[i][pre];
            }

            int up = isLimit ? n >> i & 1 : 1;
            int res = dfs(i - 1, false, isLimit && up == 0);
            if (!pre && up == 1) {
                res += dfs(i - 1, true, isLimit);
            }
            if (!isLimit) {
                memo[i][pre] = res;
            }
            return res;
        };

        return dfs(m, false, true);
    }
};

int main() {
    Solution sol;

    return 0;
}