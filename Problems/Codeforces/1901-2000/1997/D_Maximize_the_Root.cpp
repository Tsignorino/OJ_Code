#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    vector<vector<int> > g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int val;
        cin >> val;
        g[val].emplace_back(i);
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ": ";
    //     for (auto &val: g[i]) {
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }

    function<int(int)> dfs = [&](int x) {
        if (g[x].empty()) {
            return vec[x];
        }
        int mn = INT_MAX;
        for (int& y : g[x]) {
            mn = min(mn, dfs(y));
        }
        if (mn > vec[x]) {
            return vec[x] + (mn - vec[x]) / 2;
        }
        return mn;
    };

    int ans = INT_MAX;
    for (int x : g[1]) {
        ans = min(ans, dfs(x));
    }
    cout << ans + vec[1] << "\n";
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
