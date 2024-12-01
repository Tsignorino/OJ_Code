// Date: 2024-12-01  星期天

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

    string s;
    cin >> s;

    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << i << "\n";
    }

    // for (int i = 0; i < n; ++i) {
    //     if ((n - i) % 2 == 0) {
    //         cout << i + 1 << " " << n - 1 << "\n";
    //     } else {
    //         cout << i + 1 << " " << n << "\n";
    //     }
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