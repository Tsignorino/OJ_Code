#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct edge {
    int u, v, w;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> pa(n + m + 1);
    iota(pa.begin(), pa.end(), 0);
    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };

    ll ans = 0;
    vector<edge> g;
    for (int i = 1; i <= m; ++i) {
        int k, cost;
        cin >> k >> cost;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            g.emplace_back(i + n, x, cost); // 虚点
        }
        ans -= cost;
    }

    ranges::sort(g, [&](edge& e1, edge& e2) { return e1.w < e2.w; });

    int cnt = 0; // 加边数
    for (edge& e : g) {
        int px = find(e.u), py = find(e.v);
        if (px == py) {
            continue;
        }
        ans += e.w;
        cnt++;
        pa[px] = py;
    }

    cout << (cnt != n + m - 1 ? -1 : ans) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
