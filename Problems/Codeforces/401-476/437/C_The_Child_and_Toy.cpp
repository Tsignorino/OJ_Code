#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int ans = 0;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        ans += min(vec[u], vec[v]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}