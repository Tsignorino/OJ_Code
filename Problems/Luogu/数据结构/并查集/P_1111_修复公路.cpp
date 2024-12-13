#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

struct Node {
    int u, v, t;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Node> g(m + 1);
    for (auto& [u, v, t] : g) {
        cin >> u >> v >> t;
    }

    ranges::sort(g, [&](const Node& a, const Node& b) { return a.t < b.t; });

    vector<int> pa(n + 1), size(n + 1, 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int x) -> int {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    };

    for (auto& [u, v, t] : g) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            continue;
        }
        pa[pu] = pv;
        size[pv] += size[pu];
        if (size[pv] == n) {
            cout << t;
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
