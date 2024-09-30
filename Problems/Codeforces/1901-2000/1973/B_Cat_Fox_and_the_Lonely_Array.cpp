#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct Info {
    ll _or;
    Info(ll _or = 0) : _or(_or) {}
};
Info operator+(const Info& a, const Info& b) {
    return Info(a._or | b._or);
}

class SegTree {
#define ls(o) o << 1
#define rs(o) o << 1 | 1
private:
    ll n;
    vector<Info> info;

public:
    // SegTree() {}
    SegTree(ll n) : n(n), info(4 * n) {} // (32 - __builtin_clz(n)) << 2
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        function<void(ll, ll, ll)> build = [&](ll o, ll l, ll r) -> void {
            if (l == r) {
                info[o] = init[l];
                return;
            }

            ll mid = l + (r - l) / 2;
            build(ls(o), l, mid);
            build(rs(o), mid + 1, r);
            info[o] = info[ls(o)] + info[rs(o)];
        };
        build(1, 1, n);
    }

    Info query(ll todoL, ll todoR, ll o, ll l, ll r) {
        if (r < todoL || todoR < l) {
            return Info();
        }
        if (todoL <= l && r <= todoR) {
            return info[o];
        }

        ll mid = l + (r - l) / 2;
        return query(todoL, todoR, ls(o), l, mid) + query(todoL, todoR, rs(o), mid + 1, r);
    }
    Info query(ll l, ll r) { return query(l, r, 1, 1, n); }
#undef ls
#undef rs
};

void solve() {
    int n;
    cin >> n;
    vector<Info> res(n + 1);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        res[i]._or = val;
    }

    SegTree tree(res);
    int l = 0, r = n + 1;
    int ans = n;
    while (l + 1 < r) {
        int k = l + (r - l) / 2;
        set<int> set;
        for (int i = 1; i + k - 1 <= n; ++i) {
            set.emplace(tree.query(i, i + k - 1)._or);
        }
        if (set.size() == 1) {
            r = k;
            ans = min(ans, r);
        } else {
            l = k;
        }
    }
    cout << ans << "\n";
}

void solve_failToPass() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int l = 0, r = n + 1;
    int ans = n;
    while (l + 1 < r) {
        int k = l + (r - l) / 2;

        set<int> set;
        for (int i = 0; i + k - 1 < n; ++i) {
            int res = 0;
            for (int j = i; j < i + k; ++j) {
                res |= vec[j];
            }
            set.insert(res);
        }
        if (set.size() == 1) {
            r = k;
            ans = min(ans, r);
        } else {
            l = k;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
