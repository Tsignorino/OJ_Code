#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

static constexpr int dir4[4][2] = {
    {-1, 0 },
    {0,  -1},
    {1,  0 },
    {0,  1 }
};

class DSU { // Implement (union by size) + (path compression)
private:
    int n;
    vector<int> pa, _size;

public:
    DSU(int n) : n(n), pa(n), _size(n, 1) { iota(pa.begin(), pa.end(), 0); }

    int find(int x) {
        assert(x >= 0 && x < n);
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    }

    void merge(int x, int y) {
        assert(x >= 0 && x < n), assert(y >= 0 && y < n);
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

    int size(int x) {
        assert(x >= 0 && x < n);
        return _size[find(x)];
    }
};

void solve() {
    int h, w, y;
    cin >> h >> w >> y;

    vector vec(h + 2, vector<int>(w + 2));
    vector<vector<pair<int, int>>> v(y + 1);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> vec[i][j];
            if (vec[i][j] <= y) {
                v[vec[i][j]].emplace_back(i, j);
            }
        }
    }

    DSU dsu((h + 2) * (w + 2));
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            if (i == 0 || j == 0 || i == h + 1 || j == w + 1) {
                dsu.merge(i * (w + 2) + j, 0);
            }
        }
    }

    int cnt = dsu.size(0);
    for (int k = 1; k <= y; k++) {
        for (auto [x, y] : v[k]) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dir4[i][0], ny = y + dir4[i][1];
                if (vec[nx][ny] <= k) {
                    dsu.merge(x * (w + 2) + y, nx * (w + 2) + ny);
                }
            }
        }
        cout << h * w - (dsu.size(0) - cnt) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}