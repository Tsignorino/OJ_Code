#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector g(n + 1, vector<int>(n + 1));
    int x, y, v;
    while (cin >> x >> y >> v) {
        g[x][y] = v;
    }

    vector f(n + 1, vector(n + 1, vector(n + 1, vector(n + 1, -1))));
    auto dfs = [&](auto&& dfs, int x = 1, int y = 1, int x2 = 1, int y2 = 1) -> int {
        int& res = f[x][y][x2][y2];
        if (res != -1) {
            return res;
        }

        if (x == n && y == n && x2 == n && y2 == n) {
            return 0;
        }

        if (x < n && x2 < n) {
            res = max(res, dfs(dfs, x + 1, y, x2 + 1, y2) + g[x + 1][y] + g[x2 + 1][y2] - g[x + 1][y] * (x + 1 == x2 + 1 && y == y2));
        }
        if (x < n && y2 < n) {
            res = max(res, dfs(dfs, x + 1, y, x2, y2 + 1) + g[x + 1][y] + g[x2][y2 + 1] - g[x + 1][y] * (x + 1 == x2 && y == y2 + 1));
        }
        if (y < n && x2 < n) {
            res = max(res, dfs(dfs, x, y + 1, x2 + 1, y2) + g[x][y + 1] + g[x2 + 1][y2] - g[x][y + 1] * (x == x2 + 1 && y + 1 == y2));
        }
        if (y < n && y2 < n) {
            res = max(res, dfs(dfs, x, y + 1, x2, y2 + 1) + g[x][y + 1] + g[x2][y2 + 1] - g[x][y + 1] * (x == x2 && y + 1 == y2 + 1));
        }
        return res;
    };

    cout << dfs(dfs) + g[1][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}