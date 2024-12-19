// Date: 2024-12-19  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;

    if (y % x) {
        cout << 0 << "\n";
    } else {
        y /= x;

        int ans = 0;
        for (int i = 1; i <= y; ++i) {
            if (y % i == 0 && gcd(i, y / i) == 1) {
                // cerr << i << " " << y / i << "\n";
                ans++;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}