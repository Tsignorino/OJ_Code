// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        int Op, a;
        cin >> Op >> a;
        if (Op == 1 && t >= 1600 && t < 2800 || Op == 2 && t >= 1200 && t < 2400) {
            t += a;
        }
    }
    cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}