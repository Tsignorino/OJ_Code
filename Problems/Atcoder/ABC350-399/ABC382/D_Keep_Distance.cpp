// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ans;
    vector<int> a(n);
    auto dfs = [&](auto&& dfs, int i, int v) -> void {
        if (i == n - 1) {
            ans.push_back(a);
            return;
        }
        for (int k = v + 10; k <= m - max(0, n - i - 2) * 10; ++k) {
            a[i + 1] = k;
            dfs(dfs, i + 1, k);
        }
    };

    for (int i = 1; i <= m - max(0, n - 1) * 10; ++i) {
        a[0] = i;
        dfs(dfs, 0, i);
    }

    cout << ssize(ans) << "\n";
    for (auto& v : ans) {
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}