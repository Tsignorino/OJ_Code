#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    // |a| = ai + i - 1
    map<ll, vector<ll>> g;
    for (int i = 1; i < n; ++i) {
        g[vec[i] + i].push_back(vec[i] + i + i);
    }

    set<ll> s;
    auto dfs = [&](auto&& dfs, ll u) {
        if (s.contains(u)) {
            return;
        }
        s.emplace(u);
        for (auto& v : g[u]) {
            dfs(dfs, v);
        }
    };
    dfs(dfs, n);
    cout << *s.rbegin() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}