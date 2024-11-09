#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
    } else if (n % 2) {
        cout << (n + 1) / 2 << "\n";
    } else {
        cout << n + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}