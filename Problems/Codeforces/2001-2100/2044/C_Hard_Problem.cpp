// Date: 2024-12-16  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    a = min(m, a);
    b = min(m, b);

    cout << a + b + min(m - a + m - b, c) << "\n";
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