// Date: 2024-12-06  星期五

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
        build(build, 1, 0, n - 1);
    }

    void modify(int id, const Info& info, int o, int l, int r) {
        if (l == r) {
            tree[o] = info;
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
    void modify(int id, const Info& info) { modify(id, info, 1, 0, n - 1); }

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
    Info query(int L, int R) { return query(L, R, 1, 0, n - 1); }

    Info queryAll() { return tree[1]; }

    template <class F>
    int findFirst(int L, int R, F& pred, int o, int l, int r) {
        if (l > R || r < L || !pred(tree[o])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = l + (r - l) / 2;
        int idx = findFirst(L, R, pred, o << 1, l, m);
        if (idx == -1) {
            idx = findFirst(L, R, pred, o << 1 | 1, m + 1, r);
        }
        return idx;
    }
    template <class F>
    int findFirst(int l, int r, F& pred) {
        return findFirst(l, r, pred, 1, 0, n - 1);
    }

    template <class F>
    int findLast(int L, int R, F& pred, int o, int l, int r) {
        if (l > R || r < L || !pred(tree[o])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = l + (r - l) / 2;
        int idx = findLast(L, R, pred, o << 1 | 1, m + 1, r);
        if (idx == -1) {
            idx = findLast(L, R, pred, o << 1, l, m);
        }
        return idx;
    }
    template <class F>
    int findLast(int l, int r, F& pred) {
        return findLast(l, r, pred, 1, 0, n);
    }
};
struct Info {
    int g = 0;
};
Info operator+(const Info& p, const Info& q) {
    Info info;
    info.g = gcd(p.g, q.g);
    return info;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    SegTree<Info> t(n);
    for (int i = 1; i < n; ++i) {
        t.modify(i, Info(abs(a[i] - a[i - 1])));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r) {
            cout << 0 << " ";
        } else {
            cout << t.query(l + 1, r).g << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}