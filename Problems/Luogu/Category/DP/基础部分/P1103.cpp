#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct item {
    int h, w;
};

void solve() {
    int n, k;
    cin >> n >> k;
    int m = n - k; // 从 n 本书中选取 m 个

    vector<item> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        auto& v = vec[i];
        cin >> v.h >> v.w;
    }
    ranges::sort(vec, [&](const item& a, const item& b) { return a.h < b.h; });

    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX / 2));
    for (int i = 1; i <= n; ++i) {
        f[i][1] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) { // 与前面 j 本相邻
            for (int l = 2; l <= min(i, m); ++l) { // l 表示放下后的长度
                f[i][l] = min(f[i][l], f[j][l - 1] + abs(vec[i].w - vec[j].w));
            }
        }
    }

    int ans = INT_MAX;
    for (int i = m; i <= n; ++i) {
        ans = min(ans, f[i][m]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
