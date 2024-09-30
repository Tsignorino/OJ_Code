#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    粉刷匠：两遍DP（木板上，木板间）
    https://www.luogu.com.cn/problem/P4158
*/

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> vec(m + 1);
    vector<int> res(t + 1);
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= m; ++i) {
            char ch;
            cin >> ch;
            vec[i] = ch - '0';
        }

        // dp[i][j][k] 表示每一行中第 i 个格子在粉刷 j 次时的最优情况，k 表示粉刷 j 次时用的颜色
        vector dp(m + 1, vector(m + 1, vector<int>(2)));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j][vec[i]] = dp[i - 1][j][vec[i]] + 1;
                dp[i][j][!vec[i]] = dp[i - 1][j][!vec[i]];

                int tmax = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]);
                dp[i][j][vec[i]] = max(dp[i][j][vec[i]], tmax + 1);
                dp[i][j][!vec[i]] = max(dp[i][j][!vec[i]], tmax);
            }
        }

        for (int i = t; i >= 1; --i) {
            for (int j = 0; j <= min(m, i); j++) {
                res[i] = max(res[i], res[i - j] + max(dp[m][j][0], dp[m][j][1]));
            }
        }
    }
    cout << res[t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
