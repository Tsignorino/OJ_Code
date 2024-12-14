#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    // f[i][j] 表示从 j 开始合并，合并出来 i 的最终位置（有点倍增的味道）
    vector f(60, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        f[v][i] = i + 1;
    }

    int ans = 0;
    for (int i = 2; i <= 58; ++i) { // 262144 = 2 ** 18, Um + 18 = 40 + 18
        for (int j = 1; j <= n; ++j) {
            if (f[i][j] == 0) {
                f[i][j] = f[i - 1][f[i - 1][j]];
            }
            if (f[i][j] != 0) {
                ans = i;
            }
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