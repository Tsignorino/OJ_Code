#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const int MX = 2e5 + 1;

ll F[MX]; // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1

ll quickPow(ll a, ll b, int p) {
    ll res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = quickPow(F[MX - 1], MOD - 2, MOD);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

ll comb(int n, int m) {
    return n < m ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int c1 = accumulate(vec.begin(), vec.end(), 0);
    int c0 = n - c1;

    ll ans = 0;
    for (int i = (k + 1) / 2; i <= min(c1, k); ++i) {
        ans = (ans + comb(c1, i) % MOD * comb(c0, k - i) % MOD) % MOD;
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