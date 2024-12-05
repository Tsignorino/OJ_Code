// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

template <typename T>
T exgcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        return x = 1, y = 0, a;
    }
    T g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    ll n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;
    n--;
    x -= a + b + c;
    if (x < 0) {
        cout << 0 << "\n";
        return;
    }

    ll x0 = 0, y0 = 0;
    ll g = exgcd(b, c, x0, y0);
    ll nb = b / g;
    ll nc = c / g;

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ll m = x - a * i;
        if (m < 0) {
            break;
        }
        if (m % g) {
            continue;
        }

        // 最小整数解
        ll x = (m / g % nc * x0 % nc + nc) % nc;
        ll y = (m - x * b) / c;

        ll lo = max((y - n + nb - 1) / nb, 0ll) - 1;
        ll hi = min((x > n ? -1ll : (n - x) / nc), (y < 0 ? -1ll : y / nb)) + 1;
        if (lo + 1 < hi) {
            ans += hi - lo - 1;
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