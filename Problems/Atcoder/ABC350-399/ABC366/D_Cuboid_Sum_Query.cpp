#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector pre(n + 1, vector(n + 1, vector<ll>(n + 1)));
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                int val;
                cin >> val;
                pre[k + 1][i + 1][j + 1] = pre[k + 1][i + 1][j] + pre[k + 1][i][j + 1] - pre[k + 1][i][j] + val;
            }
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int a1, a2, b1, b2, c1, c2;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        ll ans = 0;
        for (int k = a1; k <= a2; ++k) {
            ans += pre[k][b2][c2] - pre[k][b1 - 1][c2] - pre[k][b2][c1 - 1] + pre[k][b1 - 1][c1 - 1];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}