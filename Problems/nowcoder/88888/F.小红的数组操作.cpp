#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88888/F

    单点修改，区间查询
*/

vector<int> tree;
vector<int> vec {0};

auto Op = [](int i, int j) {
    return min(i, j);
};

void build(int o, int l, int r) {
    if (l == r) {
        tree[o] = vec[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(o << 1, l, m), build(o << 1 | 1, m + 1, r);
    tree[o] = Op(tree[o << 1], tree[o << 1 | 1]);
}

void update(int id, int k, int o, int l, int r) {
    if (l == r) {
        tree[o] = k;
        return;
    }
    int m = l + (r - l) / 2;
    if (id <= m) {
        update(id, k, o << 1, l, m);
    } else {
        update(id, k, o << 1 | 1, m + 1, r);
    }
    tree[o] = Op(tree[o << 1], tree[o << 1 | 1]);
}

int query(int todol, int todor, int o, int l, int r) {
    if (todor < l || r < todol) {
        return INT_MAX;
    }
    if (todol <= l && r <= todor) {
        return tree[o];
    }
    int m = l + (r - l) / 2;
    return Op(query(todol, todor, o << 1, l, m), query(todol, todor, o << 1 | 1, m + 1, r));
}

void solve() {
    int n;
    cin >> n;

    vector<int> lens;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        lens.emplace_back(m);
        for (int i = 0; i < m; ++i) {
            int val;
            cin >> val;
            vec.emplace_back(val);
        }
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + lens[i];
    }

    const int N = vec.size();
    tree.resize(N << 2, INT_MAX / 2);
    build(1, 1, N);

    int q;
    cin >> q;
    while (q--) {
        int Op;
        cin >> Op;

        if (Op == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            update(pre[i - 1] + j, k, 1, 1, N);
        } else {
            int i;
            cin >> i;
            cout << query(1, pre[i], 1, 1, N) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}