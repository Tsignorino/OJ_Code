#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    https://www.luogu.com.cn/article/3zhrb4e5   还有另一种DP解法
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int mx = 0;
    for (int& v : vec) {
        cin >> v;
        mx = max(mx, v); // 注意无法合并时，单点最大值的更新
    }

    vector dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = vec[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
            for (int k = l; k < r; ++k) {
                if (dp[l][k] > 0 && dp[l][k] == dp[k + 1][r]) {
                    dp[l][r] = dp[l][k] + 1;
                    mx = max(mx, dp[l][r]);
                }
            }
        }
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}