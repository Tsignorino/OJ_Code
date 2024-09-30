#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;

    int a = max(l, L), b = min(r, R);
    if (b < a) {
        cout << 1 << "\n";
        return;
    }

    int ans = b - a;
    if (min(l, L) < a) {
        ans++;
    }
    if (max(r, R) > b) {
        ans++;
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