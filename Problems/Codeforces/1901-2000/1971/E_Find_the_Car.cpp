#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int L, n, q;
    cin >> L >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    while (q--) {
        int d;
        cin >> d;

        int id = ranges::lower_bound(a, d) - a.begin();
        if (a[id] == d) {
            cout << b[id] << " ";
            continue;
        }
        cout << (d - a[id - 1]) * 1ll * (b[id] - b[id - 1]) / (a[id] - a[id - 1]) + b[id - 1] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
