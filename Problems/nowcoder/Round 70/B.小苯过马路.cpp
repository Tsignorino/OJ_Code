// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, y, k, t;
    char ch;
    cin >> x >> y >> k >> t >> ch;

    if (ch == 'G') {
        if (k >= t) {
            cout << t << "\n";
        } else {
            cout << k + x + t << "\n";
        }
    } else {
        cout << k + t << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}