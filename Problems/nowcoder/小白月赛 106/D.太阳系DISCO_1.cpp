// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;

    constexpr int inf = 1e9;

    auto go = [&](int u, int p) {
        return (u + p - 1) % n + 1;
    };

    // 技能最多用一次
    vector<int> dis(n + 1, inf);
    dis[a] = 0;
    queue<int> q;
    q.emplace(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int v = go(u, x);
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            q.emplace(v);
        }

        v = go(u, n - y);
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            q.emplace(v);
        }
    }

    int ans = dis[b];
    if (k) {
        ans = min(ans, dis[go(b, n / 2)] + 1);
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}