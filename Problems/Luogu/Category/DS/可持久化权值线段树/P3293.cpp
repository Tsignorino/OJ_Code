#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
贪心：b ^ (a + x)

考虑从高位到低位贪心：
    初始 ans = 0，
    如果 b 的某一位为 0，那么希望 a+x 对应位为 1，搜索范围为 [ans + (1 << j), ans + (1 << (j+1)) - 1]，否则为 [ans, ans + (1 << j) - 1]
*/

struct Node {
    int l, r, cnt;
};

vector<Node> f;
int rk = 0;
auto clone(int x) {
    return f[++rk] = f[x], f[rk].cnt++, rk;
}
auto build(int& x, int l, int r) {
    x = ++rk;
    if (l == r) return;
    int mid = l + (r - l) / 2;
    build(f[x].l, l, mid);
    build(f[x].r, mid + 1, r);
}
auto update(int& x, int l, int r, int k) {
    x = clone(x);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (k <= mid) {
        update(f[x].l, l, mid, k);
    } else {
        update(f[x].r, mid + 1, r, k);
    }
}
auto query(int pre, int cur, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int l1 = f[cur].l, l2 = f[pre].l; // 通过两个时刻同一位置的 cnt 值相减，得到位于 [l, r] 子区间内的元素数量
    int cnt = f[l1].cnt - f[l2].cnt;
    int mid = l + (r - l) / 2;
    if (cnt >= k) {
        return query(f[pre].l, f[cur].l, l, mid, k);
    }
    return query(f[pre].r, f[cur].r, mid + 1, r, k - cnt);
}
auto query(int pre, int cur, int l, int r, int L, int R) -> bool {
    if (f[cur].cnt - f[pre].cnt < 1) return false;
    if (L <= l && r <= R) return true;

    int tmp = 0;
    int mid = l + (r - l) / 2;
    if (L <= mid) tmp += query(f[pre].l, f[cur].l, l, mid, L, R);
    if (R > mid) tmp += query(f[pre].r, f[cur].r, mid + 1, r, L, R);
    return tmp;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = ranges::max(a);
    vector<int> root(n + 1);
    f.resize(n << 5); // 基于值域划分
    build(root[0], 1, mx);
    for (int i = 1; i <= n; i++) {
        root[i] = root[i - 1];
        update(root[i], 1, mx, a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int b, x, l, r;
        cin >> b >> x >> l >> r;

        int ans = 0;
        for (int j = 17, lo, hi, tt = 0; j >= 0; j--) {
            int mask = (1 << j);
            if (b & mask) {
                lo = ans, hi = ans + (1 << j) - 1, tt = 0;
            } else {
                lo = ans + (1 << j), hi = ans + (1 << (j + 1)) - 1, tt = 1;
            }
            if (!query(root[l - 1], root[r], 1, mx, max(lo - x, 1), min(hi - x, mx))) {
                tt ^= 1;
            }
            ans += (tt << j);
        }
        cout << (ans ^ b) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}