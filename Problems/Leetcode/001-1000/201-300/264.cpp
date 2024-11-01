#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2, p_2 = 1, p_3 = 1, p_5 = 1; i <= n; ++i) {
            int cur = min({dp[p_2] * 2, dp[p_3] * 3, dp[p_5] * 5});
            if (cur == dp[p_2] * 2) {
                p_2++;
            }
            if (cur == dp[p_3] * 3) {
                p_3++;
            }
            if (cur == dp[p_5] * 5) {
                p_5++;
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    return 0;
}