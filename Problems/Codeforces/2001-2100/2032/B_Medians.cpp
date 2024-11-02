#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        return;
    }
    if (k == 1 || k == n) {
        cout << -1 << "\n";
        return;
    }

    cout << 3 << "\n";
    if (k % 2 == 0) {
        cout << format("{} {} {}", 1, k, k + 1) << "\n";
    } else {
        cout << format("{} {} {}", 1, k - 1, k + 2) << "\n";
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