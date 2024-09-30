#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const int N = 1000;
int f[N][N][10][10];

int query(int l, int d, int r, int u) {
    int k1 = __lg(r - l), k2 = __lg(u - d);
    return max({f[l][d][k1][k2], f[r - (1 << k1)][d][k1][k2], f[l][u - (1 << k2)][k1][k2], f[r - (1 << k1)][u - (1 << k2)][k1][k2]});
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector vec(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == 0) {
                f[i][j][0][0] = 0;
            } else {
                f[i][j][0][0] = 1;
                if (i > 0 && j > 0) {
                    f[i][j][0][0] += min({f[i - 1][j][0][0], f[i][j - 1][0][0], f[i - 1][j - 1][0][0]});
                }
            }
        }
    }

    for (int k1 = 0; k1 < 10; ++k1) {
        for (int k2 = 0; k2 < 10; ++k2) {
            for (int i = 0; i + (1 << k1) <= n; ++i) {
                for (int j = 0; j + (1 << k2) <= m; ++j) {
                    if (k1 == 0 && j + (2 << k2) <= m) {
                        f[i][j][k1][k2 + 1] = max(f[i][j][k1][k2], f[i][j + (1 << k2)][k1][k2]);
                    }
                    if (i + (2 << k1) <= n) {
                        f[i][j][k1 + 1][k2] = max(f[i][j][k1][k2], f[i + (1 << k1)][j][k1][k2]);
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;

        int l = 0, r = min(x2 - x1, y2 - y1) + 1;
        while (l + 1 < r) {
            int k = l + (r - l) / 2;
            if (query(x1 + k - 1, y1 + k - 1, x2, y2) >= k) {
                l = k;
            } else {
                r = k;
            }
        }
        cout << l << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
