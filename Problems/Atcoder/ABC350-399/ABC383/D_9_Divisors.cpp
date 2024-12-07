// Date: 2024-12-07  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

vector<int> isPrime;
vector<int> primes;
void sieve(int n) {
    isPrime.assign(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (auto j = i * 1ll * i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
}

ll qpow(ll a, ll b, ll res = 1) {
    for (; b; b >>= 1, a *= a) {
        if (b & 1) {
            res = res * a;
        }
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll ans = 0;
    int m = primes.size();
    for (int i = 0; i < m; ++i) {
        int u = primes[i];
        if (u * 1ll * u > n) {
            break;
        }
        for (int j = i + 1; j < m; ++j) {
            int v = primes[j];
            if (u * 1ull * u * v * v > n) {
                break;
            }
            ans++;
        }
    }
    // debug(ans);
    for (int v : primes) {
        if (qpow(v, 8) > n) {
            break;
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(2e6 + 5);

    solve();

    return 0;
}