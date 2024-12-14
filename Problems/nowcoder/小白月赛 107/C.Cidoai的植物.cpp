// Date: 2024-12-13  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

unsigned seed;
unsigned rnd() {
    unsigned ret = seed;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k >> seed;

    vector g(n + 1, vector<int>(m + 1));
    vector<vector<int>> s(m + 1); // vector 比 set 快得多
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            s[i].emplace_back(j);
        }
    }

    while (k--) {
        int Op = (rnd() % 2) + 1;
        if (Op == 1) {
            int i = (rnd() % m) + 1;
            int x = (rnd() % (n * m)) + 1;
            if (s[i].empty()) {
                continue;
            }
            for (auto& v : s[i]) {
                g[v][i] = x;
            }
            s[i].clear();
        } else {
            int a = (rnd() % n) + 1;
            int b = (rnd() % m) + 1;
            g[a][b] = 0;
            s[b].emplace_back(a);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans ^= g[i][j] * 1ll * ((m * (i - 1)) + j);
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