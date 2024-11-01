#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dir[9][2] {
    {0,  0 },
    {1,  2 },
    {1,  -2},
    {2,  1 },
    {2,  -1},
    {-1, 2 },
    {-1, -2},
    {-2, 1 },
    {-2, -1}
};

void solve() {
    int x, y, m, n;
    cin >> x >> y >> m >> n;

    vector<vector<ll>> dp(x + 1, vector<ll>(y + 1, -1));
    for (int i = 0; i <= x; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= y; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 0; i < 9; ++i) {
        int dx = m + dir[i][0], dy = n + dir[i][1];
        if (dx < 0 || dx > x || dy < 0 || dy > y) {
            continue;
        }
        dp[dx][dy] = 0;

        /*
          !  hack：20 20 4 0
            如果马的控制点置零之后，第一行、第一列还需要置零操作
        */
        if (dx == 0) {
            for (int i = dy; i <= y; ++i) {
                dp[0][i] = 0;
            }
        }
        if (dy == 0) {
            for (int i = dx; i <= x; ++i) {
                dp[i][0] = 0;
            }
        }
    }

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (dp[i][j]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << (dp[x][y] <= -1 ? 0 : dp[x][y]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}