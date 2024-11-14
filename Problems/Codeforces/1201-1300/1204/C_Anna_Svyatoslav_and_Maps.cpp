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

    vector g(n, vector<int>(n, n + 1));
    for (int i = 0; i < n; ++i) {
        g[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            if (ch == '1') {
                g[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (g[i][k] == n + 1) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int m;
    cin >> m;

    vector<int> a(m);
    for (int& v : a) {
        cin >> v;
        v--;
    }

    vector<int> ans {a[0]};
    int p = 0;
    while (p < m - 1) {
        int np = p;
        while (np < m - 1 && g[a[p]][a[np + 1]] == g[a[p]][a[np]] + 1) {
            np++;
        }
        ans.push_back(a[np]);
        p = np;
    }

    cout << ans.size() << "\n";
    for (int& v : ans) {
        cout << v + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}