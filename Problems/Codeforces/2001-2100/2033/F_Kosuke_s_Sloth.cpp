#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    int k;
    cin >> n >> k;

    int a = 0, b = 1 % k;
    ll res = 0;
    do {
        tie(a, b) = pair(b, (a + b) % k);
        res++;
    } while (a);
    cout << res * (n % MOD) % MOD << "\n";
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