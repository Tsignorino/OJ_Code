#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << 0 << "\n";
        return;
    }

    k -= min(k, n);
    int ans = 1, cnt = 1;
    while (k > 0) {
        k -= min(k, n - cnt);
        ans++;
        if (k > 0) {
            k -= min(k, n - cnt);
            ans++;
        }
        cnt++;
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