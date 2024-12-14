// Date: 2024-12-13  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    for (int v : {a, b, c}) {
        if (n >= v) {
            ans += n / v;
            n -= n / v * v;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}