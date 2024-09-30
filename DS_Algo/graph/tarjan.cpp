#include <bits/stdc++.h>

using namespace std;

/*
    求连通分量、割点

    引入：DFS 生成树（无向图）
        性质：
            1> T 的根节点是一个割点，当且仅当根节点有两个或更多的子节点
            2> T 的非根节点 cur 是一个割点，当且仅当 cur 存在一个 nxt 子节点，且 nxt 和它的后代都没有回退边连向 cur 的祖先
*/

constexpr int N = 2e4 + 50;
vector<int> adj[N];
vector<int> low(N), dfn(N);
vector<int> isCut(N);
int cnt = 0, root;

void tarjan(int cur, int pa) {
    low[cur] = dfn[cur] = ++cnt;
    int child = 0;
    for (int nxt : adj[cur]) {
        if (!dfn[nxt]) {
            child++;
            tarjan(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
            if (low[nxt] >= dfn[cur] && cur != root) {
                isCut[cur] = 1;
            }
        } else if (dfn[nxt] < dfn[cur] && nxt != pa) {
            low[cur] = min(low[cur], dfn[nxt]);
        }

        if (cur == root && child >= 2) {
            isCut[root] = 1;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m; // 点数，边数
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (root = 1; root <= n; ++root) {
        if (!dfn[root]) {
            tarjan(root, -1);
        }
    }

    vector<int> ans;
    for (int i = 1; i < N; ++i) {
        if (isCut[i]) {
            ans.emplace_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int node : ans) {
        cout << node << " ";
    }
}