// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int w, b;
    cin >> w >> b;

    int k = sqrt((w + b) * 2ll);
    if (k * 1ll * (k + 1) / 2 > w + b) {
        k--;
    }
    cout << k << "\n";
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