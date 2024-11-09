#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int& v : c) {
        cin >> v;
    }

    vector<int> npos(n);
    // vector<int> inDeg(n);
    for (int& v : npos) {
        cin >> v;
        v--;
        // inDeg[v]++;
    }

    // vector<int> vis(n, -1);
    // queue<int> q;
    // for (int i = 0; i < n; ++i) {
    //     if (inDeg[i] == 0) {
    //         q.emplace(i);
    //     }
    // }
    // while (!q.empty()) {
    //     int u = q.front();
    //     q.pop();
    //     vis[u] = 1;
    //     if (int v = npos[u]; --inDeg[v] == 0) {
    //         q.emplace(v);
    //     }
    // }
    //
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (vis[i] == -1) {
    //         int mn = 1e9;
    //         int v = i;
    //         while (vis[v] == -1) {
    //             vis[v] = 1;
    //             if (c[v] < mn) {
    //                 mn = c[v];
    //             }
    //             v = npos[v];
    //         }
    //         ans += mn;
    //     }
    // }
    // cout << ans << "\n";

    int ans = 0;
    vector<int> vis(n, -1);
    for (int i = 0; i < n; ++i) {
        if (vis[i] == -1) {
            int u = i;
            while (vis[u] == -1) {
                vis[u] = i;
                u = npos[u];
            }
            if (vis[npos[u]] == i) {
                int res = c[u];
                int v = u;
                while (npos[v] != u) {
                    v = npos[v];
                    res = min(res, c[v]);
                }
                ans += res;
            }
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