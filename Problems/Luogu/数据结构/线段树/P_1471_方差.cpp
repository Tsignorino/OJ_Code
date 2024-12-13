#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr ll inf = 9e18;

template <class Info, class Tag>
class SegTree {
public:
    int n;
    vector<Info> info;
    vector<Tag> tag;

public:
    SegTree() : n(0) {}
    SegTree(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
    template <class T>
    SegTree(vector<T>& init_) {
        init(init_);
    }

    template <class T>
    void init(vector<T>& init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());

        auto build = [&](auto&& build, int o, int l, int r) {
            if (l + 1 == r) {
                info[o] = init_[l];
                return;
            }
            int m = l + (r - l) / 2;
            build(build, o << 1, l, m);
            build(build, o << 1 | 1, m, r);
            pull(o);
        };
        build(build, 1, 0, n);
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
    double add = 0;
    void apply(const Tag& t) { add += t.add; }
};

struct Info {
    double sum = 0, len = 0, square = 0;
    void apply(const Tag& t) {
        square += 2.0 * t.add * sum + len * t.add * t.add;
        sum += len * t.add;
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.sum + b.sum, a.len + b.len, a.square + b.square);
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Info> vec(n);
    for (auto& v : vec) {
        cin >> v.sum;
        v.len = 1;
        v.square = v.sum * v.sum;
    }

    SegTree<Info, Tag> tree(vec);

    while (q--) {
        int Op, x, y;
        cin >> Op >> x >> y;
        x--;

        if (Op == 1) {
            double k;
            cin >> k;
            tree.rangeModify(x, y, Tag(k));
        } else if (Op == 2) {
            auto [sum, len, square] = tree.rangeQuery(x, y);
            cout << fixed << setprecision(4) << sum / len << "\n";
        } else {
            auto [sum, len, square] = tree.rangeQuery(x, y);
            cout << fixed << setprecision(4) << (square - 2 * sum * sum / len) / len + sum * sum / len / len << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}