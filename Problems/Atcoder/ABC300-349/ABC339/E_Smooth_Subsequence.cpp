#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> tree;

auto Op = [](int i, int j) {
    return max(i, j);
};

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
        return 0;
    }
    if (todol <= l && r <= todor) {
        return tree[o];
    }
    int m = l + (r - l) / 2;
    return Op(query(todol, todor, o << 1, l, m), query(todol, todor, o << 1 | 1, m + 1, r));
}

/*
    线段树优化 DP
    （刚开始错想成了 `权值线段树`）

    单点（覆盖式）更新，区间查询 —— 查询 [a-d, a+d] 中最大值，修改 a 处的值
*/
void solve() {
    int n, d;
    cin >> n >> d;

    constexpr int N = 5e5 + 1;
    tree.resize(N << 2);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        int v = query(max(0, a - d), min(a + d, N), 1, 0, N);
        update(a, v + 1, 1, 0, N);
    }
    cout << query(0, N, 1, 0, N) << "\n";

    /*
    下标从 1 开始
    */
    // for (int i = 0; i < n; ++i) {
    //     int a;
    //     cin >> a;
    //
    //     int v = query(max(0, a - d) + 1, min(a + d + 1, N), 1, 1, N);
    //     update(a + 1, v + 1, 1, 1, N);
    // }
    // cout << query(1, N, 1, 1, N) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}