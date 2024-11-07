#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    cout << 2000 << "\n";
    for (int i = 1; i <= 1000; i++) {
        cout << format("{} {} {} {}", i, 1, i, 2) << "\n";
    }
    for (int i = 1000; i >= 1; i--) {
        cout << format("{} {} {} {}", i, 1, i, 2) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}