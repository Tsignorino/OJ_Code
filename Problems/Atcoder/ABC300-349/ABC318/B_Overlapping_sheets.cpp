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

    vector g(100, vector<int>(100));
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) {
            swap(a, b);
        }
        if (c > d) {
            swap(c, d);
        }

        for (int x = a; x < b; ++x) {
            for (int y = c; y < d; ++y) {
                g[x][y] = 1;
            }
        }
    }

    int ans = 0;
    for (auto& v : g) {
        ans += accumulate(v.begin(), v.end(), 0);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}