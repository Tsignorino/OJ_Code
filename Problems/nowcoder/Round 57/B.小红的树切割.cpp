#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88888/B

    森林的每棵树都是“好树” ==> 每两个相同的都要截断
*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ans += s[u] == s[v];
    }
    cout << ans << "\n";

    // s.insert(s.begin(), ' ');
    // 
    // vector<vector<int>> g(n + 1);
    // for (int i = 0; i < n - 1; ++i) {
    //     int u, v;
    //     cin >> u >> v;
    //     g[u].emplace_back(v);
    //     g[v].emplace_back(u);
    // }
    //
    // auto dfs = [&](auto&& self, int u, int pa) -> int {
    //     int cnt = 0;
    //     for (int v : g[u]) {
    //         if (v == pa) {
    //             continue;
    //         }
    //         if (s[v] == s[u]) {
    //             cnt++;
    //         }
    //         cnt += self(self, v, u);
    //     }
    //     return cnt;
    // };
    //
    // cout << dfs(dfs, 1, -1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}