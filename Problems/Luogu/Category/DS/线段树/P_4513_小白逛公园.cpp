#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = numeric_limits<ll>::max();

struct Node {
    ll sum, SL, SR, ans;
};

vector<Node> tree;
vector<int> vec;

void pull(int o) {
    tree[o].sum = tree[o << 1].sum + tree[o << 1 | 1].sum;
    tree[o].SL = max(tree[o << 1].SL, tree[o << 1].sum + tree[o << 1 | 1].SL);
    tree[o].SR = max(tree[o << 1].SR + tree[o << 1 | 1].sum, tree[o << 1 | 1].SR);
    tree[o].ans = max({tree[o << 1].ans, tree[o << 1 | 1].ans, tree[o << 1].SR + tree[o << 1 | 1].SL});
}

void modify(int id, ll v, int o, int l, int r) {
    if (l == r) {
        tree[o] = {v, v, v, v};
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

Node query(int L, int R, int o, int l, int r) {
    if (R < l || r < L) {
        return {-inf, -inf, -inf, -inf};
    }
    if (L <= l && r <= R) {
        return tree[o];
    }
    int m = l + (r - l) / 2;
    if (R <= m) {
        return query(L, R, o << 1, l, m);
    } else if (L > m) {
        return query(L, R, o << 1 | 1, m + 1, r);
    } else {
        Node p1 = query(L, R, o << 1, l, m);
        Node p2 = query(L, R, o << 1 | 1, m + 1, r);
        return {p1.sum + p2.sum, max(p1.SL, p1.sum + p2.SL), max(p1.SR + p2.sum, p2.SR), max({p1.ans, p2.ans, p1.SR + p2.SL})};
    }
}

void build(int o, int l, int r) {
    if (l == r) {
        tree[o] = {vec[l], vec[l], vec[l], vec[l]};
        return;
    }
    int m = l + (r - l) / 2;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
    pull(o);
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
        int Op, a, b;
        cin >> Op >> a >> b;

        if (Op == 1) {
            if (a > b) {
                swap(a, b);
            }
            cout << query(a, b, 1, 1, n).ans << "\n";
        } else {
            modify(a, b, 1, 1, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}