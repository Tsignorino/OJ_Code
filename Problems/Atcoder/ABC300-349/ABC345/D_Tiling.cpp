#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, h, w;
    cin >> n >> h >> w;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector f(h, vector<int>(w));

    vector<int> vis(n);
    auto dfs = [&](auto self, int x, int y) -> void {
        if (x == h) {
            cout << "Yes\n";
            return;
        }
        if (y == w) {
            return self(self, x + 1, 0);
        }
        if (f[x][y]) {
            return self(self, x, y + 1);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                for (int t = 0; t < 2; t++) {
                    if (x + a[i] <= h && y + b[i] <= w) {
                        int ok = 1;
                        for (int u = 0; u < a[i]; u++) {
                            for (int v = 0; v < b[i]; v++) {
                                if (f[x + u][y + v]) {
                                    ok = 0;
                                }
                            }
                        }
                        if (ok) {
                            for (int u = 0; u < a[i]; u++) {
                                for (int v = 0; v < b[i]; v++) {
                                    f[x + u][y + v] = 1;
                                }
                            }
                            self(self, x, y + 1);
                            for (int u = 0; u < a[i]; u++) {
                                for (int v = 0; v < b[i]; v++) {
                                    f[x + u][y + v] = 0;
                                }
                            }
                        }
                    }
                    swap(a[i], b[i]);
                }
                vis[i] = 0;
            }
        }
    };
    dfs(dfs, 0, 0);

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
