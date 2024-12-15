// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int dx[] = {1, 0, -1, 0};
static constexpr int dy[] = {0, 1, 0, -1};

void solve() {
    int H, W, X;
    cin >> H >> W >> X;

    int P, Q;
    cin >> P >> Q;
    P--, Q--;

    vector g(H, vector<ll>(W));
    for (auto& vec : g) {
        for (auto& v : vec) {
            cin >> v;
        }
    }

    vector vis(H, vector<int>(W));
    vis[P][Q] = 1;

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    for (int k = 0; k < 4; ++k) {
        int x = P + dx[k], y = Q + dy[k];
        if (x >= 0 && x < H && y >= 0 && y < W) {
            vis[x][y] = 1;
            pq.emplace(g[x][y], x, y);
        }
    }

    ll ans = g[P][Q];
    while (!pq.empty()) {
        auto [u, p, q] = pq.top();
        pq.pop();
        if (__int128(u) * X >= ans) { // !
            break;
        }
        ans += u;
        for (int k = 0; k < 4; ++k) {
            int x = p + dx[k], y = q + dy[k];
            if (x >= 0 && x < H && y >= 0 && y < W && vis[x][y] == 0) {
                vis[x][y] = 1;
                pq.emplace(g[x][y], x, y);
            }
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