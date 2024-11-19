#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dx[] = {1, 0, -1, 0};
static constexpr int dy[] = {0, 1, 0, -1};

void solve() {
    int n, q;
    cin >> n >> q;

    const int MX = 1000;
    vector g(MX, vector<int>(MX));
    g[MX / 2][MX / 2] = n;

    auto dfs = [&](this auto&& dfs, int x, int y) {
        if (g[x][y] < 4) {
            return;
        }

        int v = g[x][y] / 4;
        g[x][y] %= 4;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            g[nx][ny] += v;
            dfs(nx, ny);
        }
    };
    dfs(MX / 2, MX / 2);

    while (q--) {
        int x, y;
        cin >> x >> y;

        if (max(abs(x), abs(y)) > MX / 2) {
            cout << 0 << "\n";
        } else {
            cout << g[x + MX / 2][y + MX / 2] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}