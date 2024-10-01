#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string r, c;
    cin >> n >> r >> c;

    int cnt = 0;
    vector<int> row(n), col(n);
    vector g(n, string(n, '.'));

    auto dfs = [&](auto&& dfs, int x, int y) {
        if (x == n) {
            if (cnt == n * 3) {
                cout << "Yes\n";
                for (int i = 0; i < n; ++i) {
                    cout << g[i] << "\n";
                }
                exit(0);
            }
            return;
        }

        if (y == n) {
            return dfs(dfs, x + 1, 0);
        }

        dfs(dfs, x, y + 1);

        for (int i = 0; i < 3; ++i) {
            if (row[x] == 0 && 'A' + i != r[x] || col[y] == 0 && 'A' + i != c[y]) {
                continue;
            }
            if (row[x] >> i & 1 || col[y] >> i & 1) {
                continue;
            }

            g[x][y] = 'A' + i;
            row[x] ^= 1 << i;
            col[y] ^= 1 << i;
            cnt++;

            dfs(dfs, x, y + 1);

            g[x][y] = '.';
            row[x] ^= 1 << i;
            col[y] ^= 1 << i;
            cnt--;
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