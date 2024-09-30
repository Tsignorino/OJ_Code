#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int ans = INT_MAX;
    for (int i = 0; i <= n / 6 + 1; ++i) {
        for (int j = 0; j <= n / 8 + 1; ++j) {
            int res = i * s + j * m;
            int cnt = i * 6 + j * 8;
            if (cnt < n) {
                res += (n - cnt + 11) / 12 * l;
            }
            ans = min(ans, res);
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