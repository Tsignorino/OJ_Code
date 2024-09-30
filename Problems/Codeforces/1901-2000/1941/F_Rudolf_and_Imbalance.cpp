#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), d(m), f(k);
    for (ll& v : a) { // 已升序
        cin >> v;
    }
    for (ll& v : d) {
        cin >> v, v *= 2;
    }
    for (ll& v : f) {
        cin >> v, v *= 2;
    }

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    ll gap = 0;
    for (int i = 0; i < n - 1; ++i) {
        gap = max(gap, a[i + 1] - a[i]);
    }

    ll ans = gap;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == gap) {
            // 寻找第二大间隔
            ll se = 0;
            for (int j = 1; j < n; ++j) {
                if (j != i) {
                    se = max(se, a[j] - a[j - 1]);
                }
            }

            // 两段间隔：a[i] - (d[p] + f[q])     (d[p] + f[q]) - a[i-1]
            ll goal = a[i] + a[i - 1], res = 4e9;
            for (int x = m - 1, y = 0; x >= 0; --x) {
                while (y < k && d[x] + f[y] < goal) {
                    y++;
                }

                if (y < k) {
                    res = min(res, d[x] + f[y] - goal);
                }
                if (y > 0) {
                    res = min(res, goal - (d[x] + f[y - 1]));
                }
            }

            res = max(se, (a[i] - a[i - 1] + res) / 2);
            ans = min(ans, res);
            break;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}