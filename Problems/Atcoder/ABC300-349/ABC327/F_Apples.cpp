#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

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
        apply(2 * o, tag[o]);
        apply(2 * o + 1, tag[o]);
        tag[o] = Tag();
    }

public:
    void modify(int o, int l, int r, int x, const Info& v) {
        if (l + 1 == r) {
            info[o] = v;
            return;
        }
        int m = l + (r - l) / 2;
        push(o);
        if (x < m) {
            modify(o << 1, l, m, x, v);
        } else {
            modify(o << 1 | 1, m, r, x, v);
        }
        pull(o);
    }
    void modify(int o, const Info& v) { modify(1, 0, n, o, v); }

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

struct Tag {
    int add = 0;
    void apply(const Tag& t) { add += t.add; }
};

struct Info {
    ll mx = 0;
    void apply(const Tag& t) { mx += t.add; }
};
Info operator+(const Info& a, const Info& b) {
    return Info(max(a.mx, b.mx));
}

void solve() {
    int n, d, w;
    cin >> n >> d >> w;

    constexpr int N = 1 << 18;

    vector<vector<pair<int, int>>> f(N);
    for (int i = 0; i < n; ++i) {
        int t, x;
        cin >> t >> x;
        f[t].emplace_back(x, 1);
        if (t + d < N) {
            f[t + d].emplace_back(x, -1);
        }
    }

    LazySegmentTree<Info, Tag> tree(N);
    ll ans = 0;
    for (int x = 0; x < N; ++x) {
        for (auto& [y, v] : f[x]) {
            tree.rangeModify(y, min(N, y + w), Tag {v});
        }
        ans = max(ans, tree.rangeQuery(0, N).mx);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}