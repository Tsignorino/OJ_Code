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
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> vec(n);
    for (auto& s : vec) {
        cin >> s;
    }

    vector vis(n, vector<int>(m));
    int ans = 0;
    auto dfs = [&](auto&& dfs, int x, int y, int k) {
        if (k == 0) {
            ans++;
            return;
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vec[nx][ny] == '.' && vis[nx][ny] == 0) {
                dfs(dfs, nx, ny, k - 1);
            }
        }
        vis[x][y] = 0;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == '#') {
                continue;
            }
            dfs(dfs, i, j, k);
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