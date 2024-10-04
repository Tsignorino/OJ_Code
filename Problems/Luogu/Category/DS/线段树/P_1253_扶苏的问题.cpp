#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

#define none numeric_limits<ll>::min()

struct Info {
    ll val, t1 = none, t2 = 0;
};

vector<Info> tree;
vector<int> vec;

void tag1(int o, ll x) {
    tree[o].val = tree[o].t1 = x;
    tree[o].t2 = 0;
}

void tag2(int o, ll x) {
    tree[o].val += x;
    if (tree[o].t1 != none) {
        tree[o].t1 += x;
    } else {
        tree[o].t2 += x;
    }
}

void push(int o) {
    if (tree[o].t1 != none) {
        tag1(o << 1, tree[o].t1);
        tag1(o << 1 | 1, tree[o].t1);
        tree[o].t1 = none;
    } else if (tree[o].t2 != 0) {
        tag2(o << 1, tree[o].t2);
        tag2(o << 1 | 1, tree[o].t2);
        tree[o].t2 = 0;
    }
}

void pull(int o) {
    tree[o].val = max(tree[o << 1].val, tree[o << 1 | 1].val);
}

void build(int o, int l, int r) {
    if (l == r) {
        tree[o].val = vec[l];
        return;
    }

    int m = l + (r - l) / 2;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
    pull(o);
}

void modify(int L, int R, ll x, int o, int l, int r, int Op) {
    if (R < l || r < L) {
        return;
    }
    if (L <= l && r <= R) {
        if (Op == 1) {
            tag1(o, x);
        } else {
            tag2(o, x);
        }
        return;
    }
    push(o);
    int m = l + (r - l) / 2;
    modify(L, R, x, o << 1, l, m, Op);
    modify(L, R, x, o << 1 | 1, m + 1, r, Op);
    pull(o);
}

ll query(int L, int R, int o, int l, int r) {
    if (R < l || r < L) {
        return none;
    }
    if (L <= l && r <= R) {
        return tree[o].val;
    }

    push(o);

    int m = l + (r - l) / 2;
    return max(query(L, R, o << 1, l, m), query(L, R, o << 1 | 1, m + 1, r));
}

void solve() {
    int n, q;
    cin >> n >> q;

    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    tree.resize(4 << __lg(n + 1));
    build(1, 1, n);

    while (q--) {
        int Op, l, r;
        cin >> Op >> l >> r;

        if (Op == 3) {
            cout << query(l, r, 1, 1, n) << "\n";
        } else {
            int x;
            cin >> x;

            modify(l, r, x, 1, 1, n, Op);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}