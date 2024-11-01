#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<vector<pair<ll, ll>>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int a, b, x;
        cin >> a >> b >> x;

        g[i].emplace_back(i + 1, a);
        g[i].emplace_back(x, b);
    }

    vector<ll> dis(n + 1, LLONG_MAX / 2);
    auto dijkstra = [&](int s = 1) {
        dis[s] = 0;

        using PLL = pair<ll, ll>;
        priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
        pq.emplace(0, s); // dis[k], k
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();

            if (d > dis[cur]) {
                continue;
            }
            for (auto& [to, w] : g[cur]) {
                if (dis[to] > d + w) {
                    dis[to] = d + w;
                    pq.emplace(dis[to], to);
                }
            }
        }
        return 0;
    }();

    cout << dis[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}