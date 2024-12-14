#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int v = ranges::max(vec);

    // f[i][j] 表示以 i 结尾的公差为 j 的等差数列的个数
    vector f(n, vector<int>((v + 1) * 2));
    int ans = 0;
    int offset = v; // 偏移
    for (int i = 0; i < n; ++i) {
        ans++;
        for (int j = i - 1; j >= 0; --j) {
            int d = vec[i] - vec[j] + offset;

            f[i][d] += f[j][d] + 1;
            f[i][d] %= MOD;

            ans += f[j][d] + 1;
            ans %= MOD;
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