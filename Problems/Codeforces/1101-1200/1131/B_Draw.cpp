#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int ans = 1; // 0, 0
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        ans += max(0, min(v1, v2) - max(p1, p2) + (p1 != p2));
        p1 = v1, p2 = v2;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
