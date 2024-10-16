#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    if (k == 0) {
        cout << 1 << "\n";
        return;
    }

    int n = s.size();
    if (k == 1) {
        cout << n - 1 << "\n";
        return;
    }

    vector memo(n, vector<int>(n + 1, -1));
    auto dfs = [&](auto&& dfs, int i, int left, bool isLimit) -> int {
        if (left == 0) {
            return 1;
        }
        if (i == n) {
            return 0;
        }

        if (!isLimit && memo[i][left] != -1) {
            return memo[i][left];
        }

        int res = 0;
        int up = isLimit ? s[i] - '0' : 1;
        for (int k = 0; k <= up; ++k) {
            res += dfs(dfs, i + 1, left - k, isLimit && k == up);
        }
        return memo[i][left] = res % MOD;
    };

    int ans = 0;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        f[i] = f[__popcount(i)] + 1;
        if (f[i] == k) {
            ans += dfs(dfs, 0, i, true);
            ans %= MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}