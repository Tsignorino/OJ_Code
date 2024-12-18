// Date: 2024-12-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g[y].emplace_back(x, w);
    }

    vector<int> inq(n + 1), cnt(n + 1);
    vector<int> dis(n + 1, numeric_limits<int>::max() / 2);
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        g[0].emplace_back(i, 0);
    }
    auto spfa = [&]() {
        queue<int> q;
        q.emplace(s);
        dis[s] = 0, inq[s] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            inq[x] = 0;
            for (auto [y, w] : g[x]) {
                if (dis[y] > dis[x] + w) {
                    dis[y] = dis[x] + w;
                    if (inq[y]) {
                        continue;
                    }
                    q.emplace(y);
                    inq[y] = 1;
                    if (++cnt[y] > n + 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    if (spfa()) {
        for (int i = 1; i <= n; ++i) {
            cout << dis[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}