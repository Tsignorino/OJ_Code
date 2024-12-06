// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

// https://blog.nowcoder.net/n/fe9675178f9446d28b56933ce192b7ab

void solve() {
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;

    constexpr int inf = 1e9;

    vector<int> fx(n + 1, inf), fy(n + 1, inf);
    for (int i = 0; i < n; ++i) {
        if (fx[i * 1ll * x % n] == inf) {
            fx[i * 1ll * x % n] = i;
        }
        if (fy[i * 1ll * y % n] == inf) {
            fy[i * 1ll * y % n] = i;
        }
    }

    int ans = inf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, fy[i] + fx[(i + b - a + n) % n]);
        if (k) {
            ans = min(ans, fy[i] + fx[(i + b - a + n + n / 2) % n] + 1);
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}