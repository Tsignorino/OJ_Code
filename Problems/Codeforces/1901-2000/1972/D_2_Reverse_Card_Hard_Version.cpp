#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

/*
    假定 g = gcd(a, b)，则 a = u * g, b = v * g
    由 gcd(u, v) == 1 <==> gcd(v, u + v) == 1 得，g % (u + v) == 0
*/
void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int u = 1; u * u <= n; ++u) {
        for (int v = 1; v * v <= m; ++v) {
            if (gcd(u, v) == 1) {
                int g = u + v;
                int a = g * u, b = g * v;
                ans += min(n / a, m / b);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
