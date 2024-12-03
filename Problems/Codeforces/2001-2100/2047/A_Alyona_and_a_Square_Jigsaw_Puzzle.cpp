// Date: 2024-12-03  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0, s = 0, a = 1; i < n; ++i) {
        int v;
        cin >> v;
        s += v;
        while (s > a * a) {
            a += 2;
        }
        if (s == a * a) {
            ans++;
        }
    }
    cout << ans << "\n";
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