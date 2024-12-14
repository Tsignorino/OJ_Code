// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static const int MOD = 19260817;
int get(const string& s) {
    int ans = 0;
    for (char ch : s) {
        ans *= 10;
        ans %= MOD;
        ans += ch - '0';
        ans %= MOD;
    }
    return ans;
}

ll qpow(ll a, ll b, int p, ll res = 1) {
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

void solve() {
    string a, b;
    cin >> a >> b;

    ll p = get(a), q = get(b);
    cout << p * qpow(q, MOD - 2, MOD) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}