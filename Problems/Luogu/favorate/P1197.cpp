#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    并查集删点操作不易实现，采用逆向思维
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int k;
    cin >> k;
    int res = n; // 记录连通块的数量
    vector<int> node(n); // 删掉的点
    stack<int> stk;
    for (int i = 0; i < k; ++i) {
        int val;
        cin >> val;

        node[val] = 1; // 标记
        stk.emplace(val);
        res--;
    }

    vector<int> pa(n);
    iota(pa.begin(), pa.end(), 0);
    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };
    function<void(int, int)> merge = [&](int i, int j) -> void {
        int pi = find(i), pj = find(j);
        if (pi != pj) {
            pa[pi] = pj;
            res--; //* 操作
        }
    };

    for (int i = 0; i < n; ++i) {
        if (node[i] == 1) {
            continue;
        }
        for (int& j : adj[i]) {
            if (node[j] == 0) {
                merge(i, j);
            }
        }
    }

    vector<int> ans {res};

    while (!stk.empty()) { // ! 用栈结构实现倒序
        int i = stk.top();
        stk.pop();
        if (node[i] == 0) {
            continue;
        }

        node[i] = 0;
        res++;
        for (int& j : adj[i]) {
            if (node[j] == 0) {
                merge(i, j);
            }
        }
        ans.emplace_back(res);
    }

    ranges::reverse(ans);
    for (int& v : ans) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
