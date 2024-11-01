#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ans += v / 2, cnt += v % 2;
    }
    cout << ans * 2 + (m - ans < cnt ? (m - ans) * 2 - cnt : cnt) << "\n";
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