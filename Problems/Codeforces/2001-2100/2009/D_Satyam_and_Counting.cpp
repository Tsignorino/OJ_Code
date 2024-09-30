#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    0 <= y <= 1
*/

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> vis(n + 1);
    vector<int> r(2);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        r[y]++, vis[x][y]++;
    }

    ll ans = 0;
    // for (int i = 0; i <= n; ++i) {
    //     if (vis[i][0] && vis[i][1]) {
    //         ans += n - 2;
    //     }
    // }
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i <= n; ++i) {
            if (vis[i][k] && vis[i][k ^ 1]) {
                ans += r[k] - 1;
            }
        }
        for (int i = 0; i + 2 <= n; ++i) {
            if (vis[i][k] && vis[i + 2][k] && vis[i + 1][k ^ 1]) {
                ans++;
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