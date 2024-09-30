#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
    static constexpr int N = 10;

public:
    int longestAwesome(string s) {
        int n = s.size();
        vector<int> pos(1 << N, n);
        pos[0] = -1; // pre[-1] = 0
        int ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            pre ^= 1 << (s[i] - '0');

            // odd
            for (int j = 0; j < N; ++j) {
                ans = max(ans, i - pos[pre ^ (1 << j)]);
            }
            // even
            ans = max(ans, i - pos[pre]);

            if (pos[pre] == n) { // 记录首次出现的下标
                pos[pre] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s("10120");
    cout << sol.longestAwesome(s);

    return 0;
}