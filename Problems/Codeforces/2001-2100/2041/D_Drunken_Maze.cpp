// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dx[] = {1, 0, -1, 0};
static constexpr int dy[] = {0, 1, 0, -1};

struct Info {
    int x, y, dir, mv;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    int sx = 0, sy = 0, tx = 0, ty = 0;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S') {
                sx = i, sy = j;
            } else if (g[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }

    queue<Info> q;
    q.emplace(sx, sy, 0, 0);

    bool vis[n][m][4][4];
    memset(vis, 0, sizeof(vis));
    vis[sx][sy][0][0] = true;

    int ans = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            auto [x, y, dir, mv] = q.front();
            q.pop();
            if (x == tx && y == ty) {
                cout << ans << "\n";
                return;
            }

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                int ndir = 0, nmv = 0;
                if (dir == k) {
                    ndir = dir;
                    nmv = mv + 1;
                } else {
                    ndir = k;
                    nmv = 1;
                }
                if (nmv > 3) {
                    continue;
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && !vis[nx][ny][ndir][nmv]) {
                    vis[nx][ny][ndir][nmv] = true;
                    q.emplace(nx, ny, ndir, nmv);
                }
            }
        }
        ans++;
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}