#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(m + 1);
    vector<pair<int, int>> state;
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        vec[p]++;
        if (p > 1) {
            state.emplace_back(c, p);
        }
    }
    if (vec[1] >= n / 2 + 1) {
        cout << 0 << "\n";
        return;
    }

    ranges::sort(state);
    int len = state.size();
    ll ans = LLONG_MAX;
    for (int i = vec[1]; i <= n / 2 + 1; ++i) {
        ll res = 0;
        int diff = i - vec[1];
        vector<int> vis(len), votes(m + 1);
        for (int j = 0; j < len; ++j) {
            auto& [c, v] = state[j];
            if (vec[v] - votes[v] >= i) {
                votes[v]++;
                res += c;
                vis[j] = 1;
                diff--;
            }
        }

        for (int j = 0; j < len && diff; ++j) {
            if (vis[j]) {
                continue;
            }

            res += state[j].first;
            diff--;
        }

        ans = min(ans, res);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
