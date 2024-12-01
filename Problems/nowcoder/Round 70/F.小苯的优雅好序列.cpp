// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    set<int> s;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s.emplace(a);
    }

    if (s.size() == 1) {
        cout << k << ' ' << k * 1ll * (k + 1) / 2 << '\n';
        return;
    }

    vector<int> a(s.begin(), s.end());

    n = a.size();
    int g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    }

    ll cnt = 0, ans = 0;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            if (int d = i - a[0]; d >= 1 && d <= k) {
                cnt++;
                ans += d;
            }
            if (g / i != i) {
                if (int d = g / i - a[0]; d >= 1 && d <= k) {
                    cnt++;
                    ans += d;
                }
            }
        }
    }
    cout << cnt << ' ' << ans << '\n';
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