#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, k;
    cin >> n >> k;

    cout << (k <= (n + 1) / 2 ? k * 2 - 1 : (k - (n + 1) / 2) * 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}