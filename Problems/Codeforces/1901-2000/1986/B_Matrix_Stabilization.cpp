#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dir4[4][2] = {
    {-1, 0 },
    {0,  -1},
    {1,  0 },
    {0,  1 }
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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int res = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dir4[k][0], ny = j + dir4[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    res = max(res, g[nx][ny]);
                }
            }
            g[i][j] = min(g[i][j], res);
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
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