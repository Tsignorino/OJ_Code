#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n + 1, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i == n) {
                return 1;
            }

            int& res = memo[i];
            if (res != -1) {
                return res;
            }

            int ans = 0;
            if (s[i] != '0') {
                ans += dfs(i + 1);
                if (i + 1 < n && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
                    ans += dfs(i + 2);
                }
            }
            return res = ans;
        };

        return dfs(0);
    }
};

int main() {
    Solution sol;

    return 0;
}