#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int a = min(x, y);
    cout << format("{} {} {} {}", 0, 0, a, a) << "\n";
    cout << format("{} {} {} {}", a, 0, 0, a) << "\n";
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