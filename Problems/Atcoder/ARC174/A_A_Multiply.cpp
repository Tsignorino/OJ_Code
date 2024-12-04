// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n, c;
    cin >> n >> c;

    ll sum = 0, pmn = 0, pmx = 0, mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        sum += v;

        pmn = min(pmn, sum);
        mx = max(mx, sum - pmn);

        pmx = max(pmx, sum);
        mn = min(mn, sum - pmx);

        // debug(pmn, pmx, mn, mx);
    }
    cout << sum + max(mx * (c - 1), mn * (c - 1)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}