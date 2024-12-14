#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<ll> f(n + 1, LLONG_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = n; j >= 1; --j) {
            for (int k = 1; k <= j; ++k) {
                f[j] = min(f[j], f[j - k] + a[i] * qpow(k, b[i]));
            }
        }
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
