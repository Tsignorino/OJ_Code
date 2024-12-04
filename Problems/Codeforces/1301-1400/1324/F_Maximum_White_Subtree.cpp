// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> ans(n);
    auto dfs = [&](this auto&& dfs, int u, int pa = -1) -> int {
        int res = a[u] == 1 ? 1 : -1;
        for (int& v : g[u]) {
            if (v == pa) {
                continue;
            }
            res += dfs(v, u);
        }
        ans[u] = res;
        return max(res, 0);
    };
    dfs(0);

    auto reroot = [&](this auto&& reroot, int u, int pa = -1) -> void {
        for (int& v : g[u]) {
            if (v == pa) {
                continue;
            }
            if (ans[v] < 0) {
                ans[v] += max(ans[u], 0);
            } else {
                ans[v] = max(ans[v], ans[u]);
            }
            reroot(v, u);
        }
    };
    reroot(0);

    for (int& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}