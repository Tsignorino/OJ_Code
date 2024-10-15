#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<int> pa(n + 1);
    vector<ll> g(n + 1);
    vector<ll> size(n + 1, 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int i) -> int {
        return i == pa[i] ? i : pa[i] = find(pa[i]);
    };

    function<void(int, int)> unite = [&](int x, int y) -> void {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }

        g[py] += g[px];
        pa[px] = py;
        size[py] += size[px];
    };

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
        g[find(u)]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int pi = find(i);
        if (g[pi] != -1) {
            ans += size[pi] * (size[pi] - 1) / 2 - g[pi];
            g[pi] = -1;
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
