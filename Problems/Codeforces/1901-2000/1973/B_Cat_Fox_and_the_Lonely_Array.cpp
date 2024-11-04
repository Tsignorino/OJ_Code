#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <class Info>
class SegTree {
    const int n;
    vector<Info> tree;

    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree(int n) : n(n), tree(4 << __lg(n)) {}
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        function<void(int, int, int)> build = [&](int o, int l, int r) {
            if (l == r) {
                tree[o] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(o << 1, l, m);
            build(o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(1, 0, n - 1);
    }

    Info query(int L, int R, int o, int l, int r) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        int m = l + (r - l) / 2;
        if (R <= m) {
            return query(L, R, o << 1, l, m);
        }
        if (m < L) {
            return query(L, R, o << 1 | 1, m + 1, r);
        }
        return query(L, R, o << 1, l, m) + query(L, R, o << 1 | 1, m + 1, r);
    }
    Info query(int L, int R) { return query(L, R, 1, 0, n - 1); }
};
struct Info {
    int or_ = 0;
};
Info operator+(const Info& p, const Info& q) {
    return Info(p.or_ | q.or_);
}

void solve() {
    int n;
    cin >> n;

    vector<Info> vec(n);
    for (auto& v : vec) {
        cin >> v.or_;
    }

    SegTree<Info> t(vec);

    auto check = [&](auto x) {
        set<int> s;
        for (int i = 0; i + x - 1 < n; ++i) {
            s.emplace(t.query(i, i + x - 1).or_);
        }
        return s.size() == 1;
    };

    int lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}

/*
// 另一种解法：

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int ans = 1;
    for (int i = 0; i < 20; ++i) {
        int pre = -1;
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] >> i & 1) {
                ans = max(ans, j - pre);
                pre = j;
            }
        }
        if (pre >= 0) {
            ans = max(ans, n - pre);
        }
    }
    cout << ans << "\n";
}
*/

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
