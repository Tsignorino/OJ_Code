#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector f(n + 2, vector<ll>(n + 1));
    vector root(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> f[i][i];
        f[i][i - 1] = 1, f[i + 1][i] = 1, root[i][i] = i;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 1, j = i + len; j <= n; ++i, ++j) {
            for (int k = i; k <= j; ++k) {
                if (f[i][j] < f[i][k - 1] * f[k + 1][j] + f[k][k]) { // !
                    f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
                    root[i][j] = k;
                }
            }
        }
    }

    cout << f[1][n] << "\n";

    function<void(int, int)> dfs = [&](int l, int r) -> void {
        if (l > r) {
            return;
        }
        cout << root[l][r] << " ";
        if (l == r) {
            return;
        }
        dfs(l, root[l][r] - 1);
        dfs(root[l][r] + 1, r);
    };
    dfs(1, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}