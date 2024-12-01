// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0
ll get(ll n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

void solve() {
    int n;
    cin >> n;

    cout << (get(n) ^ (n % 2)) << "\n";

    // if (n % 4 == 1) {
    //     cout << 0 << "\n";
    // } else if (n % 4 == 3) {
    //     cout << 1 << "\n";
    // } else if (n % 4 == 2) {
    //     cout << n + 1 << "\n";
    // } else {
    //     cout << n << "\n";
    // }
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