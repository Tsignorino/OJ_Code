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

    vector<int> p(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> r[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int t, d;
        cin >> t >> d;
        t--;

        d += (r[t] - d % p[t] + p[t]) % p[t];
        cout << d << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}