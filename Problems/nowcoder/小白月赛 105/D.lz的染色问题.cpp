// Date: 2024-11-22  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct DSU { // Implement (union by size) + (path compression)
    vector<int> pa, _size;

    DSU(int n) : pa(n), _size(n, 1) { iota(pa.begin(), pa.end(), 0); }

    // int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    int find(int x) {
        int root = x;
        while (pa[root] != root) {
            root = pa[root];
        }
        while (pa[x] != root) {
            tie(pa[x], x) = pair(root, pa[x]);
        }
        return root;
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        if (_size[px] > _size[py]) {
            swap(px, py);
        }
        pa[px] = py;
        _size[py] += _size[px];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
    }

    DSU dsu(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }

    vector<vector<int>> groupColors(n + 1);
    for (int i = 1; i <= n; ++i) {
        groupColors[dsu.find(i)].push_back(colors[i]);
    }

    // 连通块大小 - 连通块最大值
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int>& vec = groupColors[i];
        if (vec.empty()) {
            continue;
        }

        ranges::sort(vec);

        int mx_freq = 1;
        int cur_freq = 1;
        for (int j = 1; j < vec.size(); ++j) {
            if (vec[j] == vec[j - 1]) {
                cur_freq++;
                if (cur_freq > mx_freq) {
                    mx_freq = cur_freq;
                }
            } else {
                cur_freq = 1;
            }
        }
        ans += vec.size() - mx_freq;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}