#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = 9e18;

template <class Info, class Tag>
class SegTree {
private:
    int n;
    vector<Info> info;
    vector<Tag> tag;

private:
    void apply(int o, const Tag& t) { tag[o].apply(t), info[o].apply(t); }
    void push(int o) { apply(o << 1, tag[o]), apply(o << 1 | 1, tag[o]), tag[o] = Tag(); }
    void pull(int o) { info[o] = info[o << 1] + info[o << 1 | 1]; }

    void modify(int x, const Info& v, int o, int l, int r) {
        if (l == r) {
            info[o] = v;
            return;
        }
        push(o);
        int m = l + (r - l) / 2;
        if (x <= m) {
            modify(x, v, o << 1, l, m);
        } else {
            modify(x, v, o << 1 | 1, m, r);
        }
        pull(o);
    }

    Info query(int x, int o, int l, int r) {
        if (l == r) {
            return info[o];
        }
        push(o);
        int m = l + (r - l) / 2;
        if (x <= m) {
            return query(x, o << 1, l, m);
        } else {
            return query(x, o << 1 | 1, m + 1, r);
        }
    }

    void rangeModify(int L, int R, const Tag& t, int o, int l, int r) {
        if (R < l || r < L) {
            return;
        }
        if (L <= l && r <= R) {
            apply(o, t);
            return;
        }
        push(o);
        int m = l + (r - l) / 2;
        rangeModify(L, R, t, o << 1, l, m);
        rangeModify(L, R, t, o << 1 | 1, m + 1, r);
        pull(o);
    }

    Info rangeQuery(int L, int R, int o, int l, int r) {
        if (R < l || r < L) {
            return Info();
        }
        if (L <= l && r <= R) {
            return info[o];
        }
        push(o);
        int m = l + (r - l) / 2;
        return rangeQuery(L, R, o << 1, l, m) + rangeQuery(L, R, o << 1 | 1, m + 1, r);
    }

public:
    SegTree() : n(0) {}
    SegTree(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template <class T>
    SegTree(vector<T>& init_) {
        init(init_);
    }

    template <class T>
    void init(const vector<T>& init_) {
        n = init_.size() - 1;
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());

        auto build = [&](auto&& self, int o, int l, int r) -> void {
            if (l == r) {
                info[o] = init_[l];
                return;
            }
            int m = l + (r - l) / 2;
            self(self, o << 1, l, m);
            self(self, o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(build, 1, 1, n);
    }

public:
    void modify(int x, const Info& v) { modify(x, v, 1, 1, n); }
    void rangeModify(int L, int R, const Tag& t) { rangeModify(L, R, t, 1, 1, n); }
    Info query(int x) { return query(x, 1, 1, n); }
    Info rangeQuery(int L, int R) { return rangeQuery(L, R, 1, 1, n); }
};

struct Tag {
    ll add = 0;
    void apply(const Tag& t) {
        if (t.add) {
            add = t.add;
        }
    }
};

struct Info {
    ll val = 0;
    void apply(const Tag& t) {
        if (t.add) {
            val = t.add;
        }
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.val | b.val);
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Info> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        vec[i].val = 1;
    }

    SegTree<Info, Tag> t(vec);

    while (q--) {
        char Op;
        int a, b;
        cin >> Op >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        if (Op == 'C') {
            int c;
            cin >> c;
            t.rangeModify(a, b, Tag(1ll << (c - 1)));
        } else {
            ll val = t.rangeQuery(a, b).val;
            // cout << "val: " << val << "\n";
            cout << __popcount(val) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}