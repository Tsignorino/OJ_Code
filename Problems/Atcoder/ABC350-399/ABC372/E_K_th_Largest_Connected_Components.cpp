#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class DSU { // Implement (union by size) + (path compression)
public:
    vector<int> pa, _size;
    vector<vector<int>> S;

public:
    DSU(int n) : pa(n), _size(n, 1), S(n) {
        iota(pa.begin(), pa.end(), 0);
        for (int i = 0; i < n; ++i) {
            S[i].emplace_back(i);
        }
    }

    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        u--;

        if (op == 1) {
            v--;

            int pu = dsu.find(u), pv = dsu.find(v);
            if (pu == pv) {
                continue;
            }
            if (dsu._size[pu] > dsu._size[pv]) {
                swap(pu, pv);
            }
            dsu.pa[pu] = pv;
            dsu._size[pv] += dsu._size[pu];

            dsu.S[pv].insert(dsu.S[pv].end(), dsu.S[pu].begin(), dsu.S[pu].end());
            ranges::sort(dsu.S[pv], greater<int>());
            if (dsu.S[pv].size() > 10) {
                dsu.S[pv].resize(10);
            }
        } else {
            auto& s = dsu.S[dsu.find(u)];
            if (s.size() < v) {
                cout << -1 << '\n';
            } else {
                cout << s[v - 1] + 1 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}