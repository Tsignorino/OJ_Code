#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int mx = 0;
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                continue;
            }

            int pre = i - dp[i - 1] - 1;
            if (pre >= 0 && s[pre] == '(') {
                dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0); // 相邻匹配 + 跳跃匹配
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};

int main() {
    Solution sol;

    return 0;
}