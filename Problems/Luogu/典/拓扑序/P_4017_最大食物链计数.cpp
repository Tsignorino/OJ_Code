#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 80112002;

void solve() {
    int n, m; // 点数、边数
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> inDeg(n), outDeg(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].emplace_back(b);
        outDeg[a]++, inDeg[b]++;
    }

    vector<int> res(n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) { // 入度为 0 的点入队
            res[i] = 1;
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            res[v] += res[u];
            res[v] %= MOD;
            if (--inDeg[v] == 0) { // 若入度减为0，则入队
                q.emplace(v);
            }
        }
    }

    // for (int& v : res) {
    //     cout << v << " ";
    // }
    // cout << "\n";

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (outDeg[i] == 0) {
            ans += res[i];
            ans %= MOD;
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