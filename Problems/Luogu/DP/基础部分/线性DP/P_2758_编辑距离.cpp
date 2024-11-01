#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector f(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
        f[0][i] = i;
    }
    for (int i = 0; i < n; ++i) {
        f[i + 1][0] = i + 1;
        for (int j = 0; j < m; ++j) {
            f[i + 1][j + 1] = a[i] == b[j] ? f[i][j] : min({f[i][j + 1], f[i + 1][j], f[i][j]}) + 1;
        }
    }
    cout << f[n][m] << "\n";

    // auto dfs = [&](auto&& dfs, int i, int j) {
    //     if (i < 0) {
    //         return j + 1;
    //     }
    //     if (j < 0) {
    //         return i + 1;
    //     }
    //     if (a[i] == b[j]) {
    //         return dfs(dfs, i - 1, j - 1);
    //     }
    //     return min({dfs(dfs, i - 1, j), dfs(dfs, i, j - 1), dfs(dfs, i - 1, j - 1)}) + 1;
    // };
    //
    // cout << dfs(dfs, n - 1, m - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}