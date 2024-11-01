#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class DSU { // Implement (union by size) + (path compression)
private:
    vector<int> pa, _size;

public:
    DSU(int n) : pa(n), _size(n, 1) { iota(pa.begin(), pa.end(), 0); }

    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }

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
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int Op, x, y;
        cin >> Op >> x >> y;
        x--, y--;

        if (Op == 1) {
            dsu.merge(x, y);
        } else {
            cout << (dsu.same(x, y) ? "Y" : "N") << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}