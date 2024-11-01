#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = 9e18;

template <class Info, class Tag>
class LazySegmentTree {
public:
    int n;
    vector<Info> info;
    vector<Tag> tag;

public:
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
    void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }

    template <class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    template <class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());

        function<void(int, int, int)> build = [&](int o, int l, int r) {
            if (l + 1 == r) {
                info[o] = init_[l];
                return;
            }
            int m = l + (r - l) / 2;
            build(o << 1, l, m);
            build(o << 1 | 1, m, r);
            pull(o);
        };
        build(1, 0, n);
    }

private:
    void apply(int o, const Tag& v) {
        info[o].apply(v);
        tag[o].apply(v);
    }

    void pull(int o) { info[o] = info[o << 1] + info[o << 1 | 1]; }
    void push(int o) {
        apply(o << 1, tag[o]);
        apply(o << 1 | 1, tag[o]);
        tag[o] = Tag();
    }

public:
    // [l, r)
    Info rangeQuery(int o, int l, int r, int x, int y) {
        if (r <= x || l >= y) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[o];
        }
        int m = l + (r - l) / 2;
        push(o);
        return rangeQuery(o << 1, l, m, x, y) + rangeQuery(o << 1 | 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }

    void rangeModify(int o, int l, int r, int x, int y, const Tag& v) {
        if (r <= x || l >= y) {
            return;
        }
        if (x <= l && r <= y) {
            apply(o, v);
            return;
        }
        int m = l + (r - l) / 2;
        push(o);
        rangeModify(o << 1, l, m, x, y, v);
        rangeModify(o << 1 | 1, m, r, x, y, v);
        pull(o);
    }
    void rangeModify(int l, int r, const Tag& v) { return rangeModify(1, 0, n, l, r, v); }
};
// 下标从 0 开始

struct Tag {
    int tag = 0;
    void apply(const Tag& t) { tag ^= t.tag; }
};

struct Info {
    int sum = 0, len = 1;
    void apply(const Tag& t) {
        if (t.tag == 1) {
            sum = len - sum;
        }
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.sum + b.sum, a.len + b.len);
}

void solve() {
    int n, q;
    cin >> n >> q;

    LazySegmentTree<Info, Tag> t(n);

    while (q--) {
        int Op, a, b;
        cin >> Op >> a >> b;
        a--;

        if (Op == 0) {
            t.rangeModify(a, b, Tag(1));
        } else {
            cout << t.rangeQuery(a, b).sum << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}