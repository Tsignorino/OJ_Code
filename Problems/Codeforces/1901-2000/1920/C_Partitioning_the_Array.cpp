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

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    auto f = [&](int d) {
        int g = 0;
        for (int i = 0; i < d; ++i) {
            for (int j = i + d; j < n; j += d) {
                g = gcd(g, a[j] - a[j - d]);
            }
        }
        return abs(g) != 1;
    };

    int ans = 0;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            ans += f(d);
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