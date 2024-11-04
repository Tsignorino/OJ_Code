#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 2) {
        cout << -1 << "\n";
    } else {
        cout << (a + b <= c ? a + b : (a + b + c) / 2) << "\n";
    }
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