#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    map<int, int> priFac;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        for (int i = 2; i * 1ll * i <= x; ++i) {
            while (x % i == 0) {
                x /= i;
                priFac[i]++;
            }
        }
        if (x > 1) {
            priFac[x]++;
        }
    };

    for (auto& [v, c] : priFac) {
        if (c % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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