// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

template <class Info>
class SegTree {
    const int n;
    vector<Info> tree;

    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree(int n) : n(n), tree(4 << __lg(n)) {}
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        auto build = [&](auto&& self, int o, int l, int r) -> void {
            if (l == r) {
                tree[o] = init[l];
                return;
            }
            int m = l + (r - l) / 2;
            self(self, o << 1, l, m);
            self(self, o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(build, 1, 1, n);
    }

    void modify(int id, const Info& info, int o, int l, int r) {
        if (l == r) {
            tree[o] = Info(tree[o].tot + info.tot);
            return;
        }
        int m = l + (r - l) / 2;
        if (id <= m) {
            modify(id, info, o << 1, l, m);
        } else {
            modify(id, info, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int id, const Info& info) { modify(id, info, 1, 1, n); }

    Info query(int L, int R, int o, int l, int r) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(L, R, o << 1, l, m);
        }
        if (m < L) {
            return query(L, R, o << 1 | 1, m + 1, r);
        }
        return query(L, R, o << 1, l, m) + query(L, R, o << 1 | 1, m + 1, r);
    }
    Info query(int L, int R) { return query(L, R, 1, 1, n); }

    Info queryAll() { return tree[1]; }
};
struct Info {
    ll ans = 0, tot = 0, pre = 0, suf = 0;
    Info() {}
    Info(ll v) { ans = v, tot = v, pre = v, suf = v; }
};
Info operator+(const Info& p, const Info& q) {
    Info info;
    info.ans = max({p.ans, q.ans, p.suf + q.pre});
    info.tot = p.tot + q.tot;
    info.pre = max(p.pre, p.tot + q.pre);
    info.suf = max(q.suf, p.suf + q.tot);
    return info;
}

void solve() {
    int n, m;
    cin >> n >> m;

    struct Item {
        int i, v;
    };
    vector<vector<Item>> Ops(n + 2);
    for (int i = 1; i <= m; ++i) {
        int l, r, v;
        cin >> l >> r >> v;
        Ops[l].emplace_back(i, v);
        Ops[r + 1].emplace_back(i, -v);
    }

    int q;
    cin >> q;

    struct Query {
        int l, r, i;
    };
    vector<vector<Query>> Qs(n + 1);
    for (int i = 0; i < q; ++i) {
        int k, s, t;
        cin >> k >> s >> t;
        Qs[k].emplace_back(s, t, i);
    }

    SegTree<Info> tree(m);
    vector<ll> ans(q);
    for (int i = 0; i < Qs.size(); ++i) {
        for (auto& [i, v] : Ops[i]) {
            tree.modify(i, v);
        }
        for (auto& [l, r, i] : Qs[i]) {
            ans[i] = tree.query(l, r).ans;
        }
    }
    for (auto& v : ans) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}