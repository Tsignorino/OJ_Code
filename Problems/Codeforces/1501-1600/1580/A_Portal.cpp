#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, string(m, ' '));
    for (string& s : g) {
        cin >> s;
    }

    int ans = n * m;
    for (int i = 0; i < n - 4; ++i) { // 枚举上边界
        vector<int> cnt(m);
        for (int j = i + 1; j < i + 4; ++j) {
            for (int k = 0; k < m; ++k) {
                cnt[k] += g[j][k] - '0';
            }
        }

        vector<int> calc(m);
        for (int j = i + 4; j < n; ++j) { // 枚举下边界
            for (int k = 0; k < m; ++k) {
                calc[k] = cnt[k];
            }
            for (int k = 1; k < m - 1; ++k) {
                calc[k] += 2 - (g[i][k] - '0') - (g[j][k] - '0');
            }
            for (int k = 1; k < m; ++k) {
                calc[k] += calc[k - 1];
            }

            int cur = n * m;
            for (int k = m - 1; k > 2; --k) {
                cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k]);
                ans = min(ans, cur - calc[k - 3] + j - i - 1 - cnt[k - 3]);
            }

            for (int k = 0; k < m; ++k) {
                cnt[k] += g[j][k] - '0';
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}