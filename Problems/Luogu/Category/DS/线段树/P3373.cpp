#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Node {
    ll sum = 0, add = 0, mul = 1;
    int l, r;
};

// 处理区间加法和区间乘法
class SegTree {
private:
    int n, m;
    vector<Node> t;

    void push_up(ll o) { t[o].sum = (t[o << 1].sum + t[o << 1 | 1].sum) % m; }
    void push_down(ll o) {
        t[o << 1].sum = (t[o << 1].sum * t[o].mul + t[o].add * (t[o << 1].r - t[o << 1].l + 1)) % m;
        t[o << 1 | 1].sum = (t[o << 1 | 1].sum * t[o].mul + t[o].add * (t[o << 1 | 1].r - t[o << 1 | 1].l + 1)) % m;

        t[o << 1].mul = t[o << 1].mul * t[o].mul % m;
        t[o << 1 | 1].mul = t[o << 1 | 1].mul * t[o].mul % m;

        t[o << 1].add = (t[o << 1].add * t[o].mul + t[o].add) % m;
        t[o << 1 | 1].add = (t[o << 1 | 1].add * t[o].mul + t[o].add) % m;

        t[o].add = 0, t[o].mul = 1;
    }

public:
    SegTree() {}
    SegTree(const vector<int>& vec, int m) : n(vec.size()), m(m), t(4 * n) {
        function<void(ll, ll, ll)> build = [&](ll o, ll l, ll r) -> void {
            t[o].l = l, t[o].r = r;
            if (l == r) {
                t[o].sum += vec[l] % m;
                return;
            }
            ll mid = l + (r - l) / 2;
            build(o << 1, l, mid);
            build(o << 1 | 1, mid + 1, r);
            push_up(o);
        };
        build(1, 1, n);
    }

    void lazyMul(ll o, ll l, ll r, ll k) {
        if (l <= t[o].l && t[o].r <= r) {
            t[o].add = (t[o].add * k) % m;
            t[o].mul = (t[o].mul * k) % m;
            t[o].sum = (t[o].sum * k) % m;
            return;
        }
        push_down(o);
        ll mid = t[o].l + (t[o].r - t[o].l) / 2;
        if (l <= mid) {
            lazyMul(o << 1, l, r, k);
        }
        if (r > mid) {
            lazyMul(o << 1 | 1, l, r, k);
        }
        push_up(o);
    }
    void lazyAdd(ll o, ll l, ll r, ll k) {
        if (l <= t[o].l && t[o].r <= r) {
            t[o].add = (t[o].add + k) % m;
            t[o].sum = (t[o].sum + k * (t[o].r - t[o].l + 1)) % m;
            return;
        }
        push_down(o);
        ll mid = t[o].l + (t[o].r - t[o].l) / 2;
        if (l <= mid) {
            lazyAdd(o << 1, l, r, k);
        }
        if (r > mid) {
            lazyAdd(o << 1 | 1, l, r, k);
        }
        push_up(o);
    }

    ll query(ll o, ll l, ll r) {
        if (l <= t[o].l && t[o].r <= r) {
            return t[o].sum;
        }
        push_down(o);
        ll val = 0, mid = t[o].l + (t[o].r - t[o].l) / 2;
        if (l <= mid) {
            val = (val + query(o << 1, l, r)) % m;
        }
        if (r > mid) {
            val = (val + query(o << 1 | 1, l, r)) % m;
        }
        return val;
    }
};

void solve() {
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    SegTree t(vec, m);

    while (q--) {
        int Op, l, r;
        cin >> Op >> l >> r;
        if (Op == 1) {
            int k;
            cin >> k;
            t.lazyMul(1, l, r, k);
        } else if (Op == 2) {
            int k;
            cin >> k;
            t.lazyAdd(1, l, r, k);
        } else {
            cout << t.query(1, l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
