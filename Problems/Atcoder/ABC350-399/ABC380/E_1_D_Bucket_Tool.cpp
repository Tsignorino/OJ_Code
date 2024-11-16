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

    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        // if (_size[px] > _size[py]) {
        //     swap(px, py);
        // }
        pa[px] = py;
        _size[py] += _size[px];
    }

    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return _size[find(x)]; }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu_l(n + 2), dsu_r(n + 2);

    vector<int> color(n + 2);
    iota(color.begin(), color.end(), 0);

    vector<int> s(n + 2, 1);

    while (q--) {
        int Op;
        cin >> Op;

        if (Op == 1) {
            int x, c;
            cin >> x >> c;

            int l = dsu_l.find(x), r = dsu_r.find(x);
            s[color[l]] -= dsu_l.size(x);
            s[c] += dsu_l.size(x);
            if (color[dsu_l.find(l - 1)] == c) {
                dsu_l.merge(l, l - 1);
                dsu_r.merge(l - 1, l);
            }
            if (color[dsu_l.find(r + 1)] == c) {
                dsu_l.merge(r + 1, r);
                dsu_r.merge(r, r + 1);
            }
            color[dsu_l.find(x)] = c;
        } else {
            int c;
            cin >> c;

            cout << s[c] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}