#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Edge {
    int v, w, id;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w, i);
        g[v].emplace_back(u, w, i);
    }

    vector<ll> dis(n, LLONG_MAX / 2);
    dis[0] = 0;

    vector<int> pa(n, -1);

    using pli = pair<ll, int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, 0); // dis, v
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dis[u]) {
            continue;
        }
        for (auto& [v, w, id] : g[u]) {
            if (dis[v] > d + w) {
                dis[v] = d + w;
                pa[v] = id;
                pq.emplace(dis[v], v);
            }
        }
    }

    /*
        一种简单的构造是，选取最短路长度最小的 min(n-1, k) 个点，容易发现，这些点是树上和 1 距离最近的点，因此也形成一个连通块。
    */
    vector<int> ids(n - 1);
    iota(ids.begin(), ids.end(), 1);
    ranges::sort(ids, [&](int i, int j) { return dis[i] < dis[j]; });

    int res = min(n - 1, k);
    cout << res << "\n";
    for (int i = 0; i < res; ++i) {
        cout << pa[ids[i]] + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}