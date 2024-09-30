#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    本来想着逆元，但是模数不是质数，没想到可以乘除转换一下，用线段树维护
*/

void solve() {
    int q, mod;
    cin >> q >> mod;

    vector<int> tree(q << 2);
    ranges::fill(tree, 1);

    function<void(int, int, int, int, int)> update = [&](int o, int l, int r, int x, int v) -> void {
        if (l == r) {
            tree[o] = v == -1 ? 1 : v;
            return;
        }
        int mid = l + (r - l) / 2;
        if (x <= mid) {
            update(o << 1, l, mid, x, v);
        } else {
            update(o << 1 | 1, mid + 1, r, x, v);
        }
        tree[o] = (tree[o << 1] * 1ll * tree[o << 1 | 1]) % mod;
    };

    for (int i = 1; i <= q; ++i) {
        int Op, v;
        cin >> Op >> v;

        if (Op == 1) {
            update(1, 1, q, i, v);
        } else {
            update(1, 1, q, v, -1);
        }
        cout << tree[1] % mod << "\n";
    }
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