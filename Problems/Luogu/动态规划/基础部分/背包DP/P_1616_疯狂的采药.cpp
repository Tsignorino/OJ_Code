#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int t, m;
    cin >> t >> m;

    vector<ll> f(t + 1);
    for (int i = 0; i < m; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = v; j <= t; ++j) {
            f[j] = max(f[j], f[j - v] + w);
        }
    }
    cout << f[t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}