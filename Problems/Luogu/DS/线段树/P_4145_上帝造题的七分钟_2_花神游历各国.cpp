#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Info {
    ll sum = 0, mx = 0;
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.sum + b.sum, max(a.mx, b.mx));
}

vector<Info> tree;
vector<ll> vec;

void pull(int o) {
    tree[o] = tree[o << 1] + tree[o << 1 | 1];
}

void modify(int L, int R, int o, int l, int r) {
    if (tree[o].mx <= 1) {
        return;
    }
    if (l == r) {
        tree[o].sum = sqrt(tree[o].sum);
        tree[o].mx = sqrt(tree[o].mx);
        return;
    }
    int m = l + (r - l) / 2;
    if (L <= m) {
        modify(L, R, o << 1, l, m);
    }
    if (R > m) {
        modify(L, R, o << 1 | 1, m + 1, r);
    }
    pull(o);
}

Info query(int L, int R, int o, int l, int r) {
    if (R < l || r < L) {
        return {0, 0};
    }
    if (L <= l && r <= R) {
        return tree[o];
    }
    int m = l + (r - l) / 2;
    return query(L, R, o << 1, l, m) + query(L, R, o << 1 | 1, m + 1, r);
}

void build(int o, int l, int r) {
    if (l == r) {
        tree[o].sum = vec[l];
        tree[o].mx = vec[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
    pull(o);
}

void solve() {
    int n;
    cin >> n;

    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    tree.resize(4 << __lg(n));
    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int Op, l, r;
        cin >> Op >> l >> r;
        if (l > r) {
            swap(l, r);
        }

        if (Op == 0) {
            modify(l, r, 1, 1, n);
        } else {
            cout << query(l, r, 1, 1, n).sum << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}