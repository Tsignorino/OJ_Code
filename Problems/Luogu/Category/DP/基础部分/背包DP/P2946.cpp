#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e8;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
        vec[i] %= m;
    }

    // f[i][j] 表示前 i 个之和 mod m 之后为 j 的方案数
    vector f(n + 1, vector<int>(m));
    for (int i = 1; i <= n; ++i) {
        f[i][vec[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            f[i][j] += f[i - 1][j] + f[i - 1][(j - vec[i] + m) % m];
            f[i][j] %= MOD;
        }
    }
    cout << f[n][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}