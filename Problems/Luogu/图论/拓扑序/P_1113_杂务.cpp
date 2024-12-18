// Date: 2024-12-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> inDeg(n);
    vector<int> T(n);
    for (int i = 0; i < n; ++i) {
        int v, t;
        cin >> v >> t;
        v--;
        T[v] = t;

        int u;
        while (cin >> u) {
            if (u == 0) {
                break;
            }
            u--;
            g[u].emplace_back(v);
            inDeg[v]++;
        }
    }
    // debug(g);
    // debug(inDeg);

    queue<int> q;
    vector<int> need(n);
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            q.emplace(i);
            need[i] = T[i];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int& v : g[u]) {
            if (--inDeg[v] == 0) {
                q.emplace(v);
            }
            need[v] = max(need[v], need[u] + T[v]);
        }
    }

    cout << ranges::max(need) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}