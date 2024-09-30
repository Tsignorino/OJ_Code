#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    // Sort by the value of array a
    vector<int> to(n + 1);
    for (int& v : a) {
        cin >> to[v];
    }

    vector<int> c(n + 1);
    for (int& v : a) {
        cin >> c[v];
    }

    // Guarantee：There's at least one legal solution
    vector<int> vis(n + 1);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }

        vis[i] = 1;

        int ok = 1;
        for (int j = to[i]; j != i; j = to[j]) {
            vis[j] = 1;
            if (c[j]) {
                ok = 0;
            }
        }
        if (i == to[i] || c[i]) {
            ok = 0;
        }

        if (ok) {
            ans = ans * 2 % MOD;
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
