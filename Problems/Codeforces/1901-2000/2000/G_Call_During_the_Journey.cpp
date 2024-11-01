#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

struct Node {
    int to, l, Op; // Op = 1, 车；Op = 0, 步行
};

void solve() {
    int n, m;
    cin >> n >> m;

    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;

    vector<vector<Node>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        u--, v--;

        g[u].emplace_back(v, l1, 1);
        g[u].emplace_back(v, l2, 0);
        g[v].emplace_back(u, l1, 1);
        g[v].emplace_back(u, l2, 0);
    }

    vector<int> dis(n, INT_MAX / 2);
    dis[n - 1] = 0;

    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> pq;
    pq.emplace(0, n - 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dis[u]) {
            continue;
        }
        
        for (auto& [v, l, Op] : g[u]) {
            int res = (Op == 0 || (dis[u] >= t0 - t1 || dis[u] + l <= t0 - t2)) ? dis[u] + l : t0 - t1 + l;
            if (res < dis[v]) {
                dis[v] = res;
                pq.emplace(dis[v], v);
            }
        }
    }

    cout << max(t0 - dis[0], -1) << "\n";
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