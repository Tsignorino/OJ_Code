#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto dfs = [&](auto&& dfs, int x, int pa) -> int {
        int ans = 1;
        for (int y : g[x]) {
            if (y != pa) {
                ans += dfs(dfs, y, x);
            }
        }
        return ans;
    };

    vector<int> res;
    for (int x : g[1]) {
        res.emplace_back(dfs(dfs, x, 1));
    }

    if (res.empty()) {
        cout << 0 << "\n";
    } else {
        cout << accumulate(res.begin(), res.end(), 0) - ranges::max(res) + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}