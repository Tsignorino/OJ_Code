#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    int cnt = n;
    for (int j = 2; j <= m; ++j) {
        ll val = j * 1ll * j;
        if (n + j < val) {
            break;
        }
        cnt += (n + j) / val;
    }
    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
