#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n_ = 0) : n(n_), tree(n, T {}) {}

    void add(int x, const T& v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            tree[i - 1] += v;
        }
    }
    T query(int x) {
        T ans {};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + tree[i - 1];
        }
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l); }

    int select(const T& k) {
        T cur {};
        int x = 0;
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + tree[x + i - 1] <= k) {
                x += i;
                cur += tree[x - 1];
            }
        }
        return x;
    }
};
// The Fenwick is aligned with the input array 0-index.

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = (pre[i] + vec[i]) % m;
    }

    ll ans = 0;
    Fenwick<ll> f(m);
    for (int i = 0; i <= n; ++i) {
        f.add(pre[i], 1);
        ans += pre[i] * (i - (n - i));
        ans += f.query(pre[i] + 1, m) * m;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}