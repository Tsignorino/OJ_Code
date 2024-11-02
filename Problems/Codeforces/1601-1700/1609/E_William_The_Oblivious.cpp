#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <class Info>
class SegTree {
    const int n;
    vector<Info> tree;

    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree(int n) : n(n), tree(4 << __lg(n)) {}
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        function<void(int, int, int)> build = [&](int o, int l, int r) {
            if (l == r) {
                tree[o] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(o << 1, l, m);
            build(o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(1, 0, n - 1);
    }

    void modify(int id, const Info& v, int o, int l, int r) {
        if (l == r) {
            tree[o] = v;
            return;
        }
        int m = l + (r - l) / 2;
        if (id <= m) {
            modify(id, v, o << 1, l, m);
        } else {
            modify(id, v, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int id, const Info& v) { modify(id, v, 1, 0, n - 1); }

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
    int a = 0, b = 0, c = 0, ab = 0, bc = 0, abc = 0;
};
Info operator+(const Info& p, const Info& q) {
    return Info(p.a + q.a, //
                p.b + q.b, //
                p.c + q.c, //
                min(p.a + q.ab, p.ab + q.b), //
                min(p.b + q.bc, p.bc + q.c), //
                min({p.a + q.abc, p.ab + q.bc, p.abc + q.c}) //
    );
}
// 当维护的信息较多，且传入构造的参数有条件时，
// 该函数可以用需要传入的参数新建节点
Info newInfo(char ch) {
    Info o;
    if (ch == 'a') {
        o.a = 1;
    } else if (ch == 'b') {
        o.b = 1;
    } else {
        o.c = 1;
    }
    return o;
}

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<Info> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = newInfo(s[i]);
    }

    SegTree<Info> t(vec);

    while (q--) {
        int id;
        char ch;
        cin >> id >> ch;
        id--;

        t.modify(id, newInfo(ch));
        cout << t.query(0, n - 1).abc << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}