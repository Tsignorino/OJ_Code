#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

long long quickPow(long long a, long long b) {
    long long res = 1;
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
                f[j] = min(f[j], f[j - k] + a[i] * quickPow(k, b[i]));
            }
        }
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
