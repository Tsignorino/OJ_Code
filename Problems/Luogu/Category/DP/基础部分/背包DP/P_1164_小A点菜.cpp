#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    // f[i][j] 表示前 i 道菜花 j 元的方法
    // 降维
    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        for (int j = m; j >= 0; --j) {
            f[j] = f[j] + (j >= v ? f[j - v] : 0);
        }
    }
    cout << f[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}