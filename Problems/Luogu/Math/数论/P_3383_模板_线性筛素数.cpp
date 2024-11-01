#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> prime, isPrime;
void sieve(int n) {
    isPrime.resize(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            prime.emplace_back(i);
        }
        for (int& p : prime) {
            if (i * p > n) {
                break;
            }
            isPrime[i * p] = 0;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    sieve(n);

    while (q--) {
        int k;
        cin >> k;
        k--;
        cout << prime[k] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}