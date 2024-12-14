#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dir[4][2] = {
    {-1, 0 },
    {0,  -1},
    {1,  0 },
    {0,  1 },
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    vector memo(n, vector<int>(m, -1));
    auto dfs = [&](auto&& dfs, int x, int y) {
        int& res = memo[x][y];
        if (res != -1) {
            return res;
        }

        res = 1;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[x][y] > g[nx][ny]) {
                dfs(dfs, nx, ny);
                res = max(res, memo[nx][ny] + 1);
            }
        }
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dfs(dfs, i, j));
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