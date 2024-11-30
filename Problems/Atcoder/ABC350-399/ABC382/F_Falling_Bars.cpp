// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = 9e18;

template <class Info, class Tag>
class SegTree {
private:
    int n;
    vector<Info> tree;
    vector<Tag> tag;

    void apply(int o, const Tag& t) { tag[o].apply(t), tree[o].apply(t); }
    void push(int o) { apply(o << 1, tag[o]), apply(o << 1 | 1, tag[o]), tag[o] = Tag(); }
    void pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

public:
    SegTree() : n(0) {}
    SegTree(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template <class T>
    SegTree(vector<T>& init_) {
        init(init_);
    }

    template <class T>
    void init(const vector<T>& init_) {
        n = init_.size();
        tree.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());

        auto build = [&](auto&& self, int o, int l, int r) -> void {
            if (l == r) {
                tree[o] = init_[l];
                return;
            }
            int m = l + (r - l) / 2;
            self(self, o << 1, l, m);
            self(self, o << 1 | 1, m + 1, r);
            pull(o);
        };
        build(build, 1, 0, n - 1);
    }

public:
    void modify(int L, int R, const Tag& t, int o, int l, int r) {
        if (L <= l && r <= R) {
            apply(o, t);
            return;
        }
        push(o);
        int m = l + (r - l) / 2;
        if (L <= m) {
            modify(L, R, t, o << 1, l, m);
        }
        if (m < R) {
            modify(L, R, t, o << 1 | 1, m + 1, r);
        }
        pull(o);
    }
    void modify(int L, int R, const Tag& t) { modify(L, R, t, 1, 0, n - 1); }

    Info query(int L, int R, int o, int l, int r) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        push(o);
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

struct Tag {
    int s = 0;
    void apply(const Tag& t) {
        if (t.s) {
            s = max(s, t.s);
        }
    }
};
struct Info {
    int mx = 0;
    void apply(const Tag& t) {
        if (t.s) {
            mx = max(mx, t.s);
        }
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(max(a.mx, b.mx));
}

struct Item {
    int r, c, l;
};

void solve() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<Item> a(n);
    for (int i = 0; i < n; ++i) {
        auto& [r, c, l] = a[i];
        cin >> r >> c >> l;
        c--;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int i, int j) { return a[i].r > a[j].r; });

    SegTree<Info, Tag> t(w + 1);

    vector<int> ans(n);
    for (int i : idx) {
        auto& [r, c, l] = a[i];
        int v = t.query(c, c + l - 1).mx;
        ans[i] = h - v;
        t.modify(c, c + l - 1, Tag(v + 1));
    }
    for (int& v : ans) {
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}