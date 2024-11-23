// Date: 2024-11-23  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename T>
constexpr T qpow(T x, uint64_t a, T res = 1) {
    for (; a; a >>= 1, x *= x) {
        if (a & 1) {
            res *= x;
        }
    }
    return res;
}

template <uint32_t P>
constexpr uint32_t mulMod(uint32_t a, uint32_t b) {
    return a * 1ull * b % P;
}

template <uint64_t P>
constexpr uint64_t mulMod(uint64_t a, uint64_t b) {
    uint64_t res = a * b - uint64_t(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template <typename T, T P>
class ModIntBase {
private:
    T x;

public:
    constexpr ModIntBase() : x(0) {}
    constexpr ModIntBase(bool b) : x(norm(static_cast<T>(b))) {}

    template <integral U>
        requires integral<U>
    constexpr ModIntBase(U x_ = 0) : x(norm(x_ % U {P})) {}

    constexpr static T norm(T x) {
        if ((x >> (8 * sizeof(T) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr T val() const { return x; }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const { return qpow(*this, P - 2); }

public:
    constexpr ModIntBase& operator*=(const ModIntBase& rv) & { return x = mulMod<P>(x, rv.val()), *this; }
    constexpr ModIntBase& operator+=(const ModIntBase& rv) & { return x = norm(x + rv.x), *this; }
    constexpr ModIntBase& operator-=(const ModIntBase& rv) & { return x = norm(x - rv.x), *this; }
    constexpr ModIntBase& operator/=(const ModIntBase& rv) & { return *this *= rv.inv(); } //

    constexpr ModIntBase& operator++() & { return x = norm(x + 1), *this; }
    constexpr ModIntBase& operator--() & { return x = norm(x - 1), *this; }

    constexpr ModIntBase operator++(int) {
        // 后置
        ModIntBase tmp(*this);
        ++*this;
        return tmp;
    }

    constexpr ModIntBase operator--(int) {
        ModIntBase tmp(*this);
        --*this;
        return tmp;
    }

    friend constexpr ModIntBase operator+(ModIntBase lv, const ModIntBase& rv) { return lv += rv; }
    friend constexpr ModIntBase operator-(ModIntBase lv, const ModIntBase& rv) { return lv -= rv; }
    friend constexpr ModIntBase operator*(ModIntBase lv, const ModIntBase& rv) { return lv *= rv; }
    friend constexpr ModIntBase operator/(ModIntBase lv, const ModIntBase& rv) { return lv /= rv; }

    friend constexpr strong_ordering operator<=>(ModIntBase lhs, ModIntBase rhs) { return lhs.val() <=> rhs.val(); }
    friend constexpr bool operator==(ModIntBase lv, const ModIntBase rv) { return lv.val() == rv.val(); }

    friend constexpr istream& operator>>(istream& in, ModIntBase& v) {
        T x;
        in >> x;
        v.x = v.norm(x % T(P));
        return in;
    }

    friend constexpr ostream& operator<<(ostream& os, const ModIntBase& v) { return os << v.val(); }
};

template <uint32_t P>
using ModInt32 = ModIntBase<uint32_t, P>;
template <uint64_t P>
using ModInt64 = ModIntBase<uint64_t, P>;

using Mint = ModInt32<MOD>;
// qpow 取模时，第一个参数应为 Mint 类型
// 默认模数是 1e9+7，注意修改...

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
    ll x = 0;
    void apply(const Tag& t) {
        if (t.x) {
            x = t.x;
        }
    }
};
struct Info {
    Mint mul = 1, tot = 0;
    int len = 0;
    void apply(const Tag& t) {
        if (t.x) {
            mul = qpow(Mint(t.x), len);
            if (t.x == 1) {
                tot = len;
            } else {
                tot = (qpow(Mint(t.x), len) - 1) * t.x * Mint(t.x - 1).inv();
            }
        }
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.mul * b.mul, a.tot + a.mul * b.tot, a.len + b.len);
}

/*
左：a1(l) + al(l) * a1(l+1) + ... + a1(l) * a1(l+1) * ... * a1(r)
右：a2(l) + a2(l) * a2(l+1) + ... + a2(l) * a2(l+1) * ... * a2(r)
合并：
    a1(l) + a1(l) * a1(l+1) + ... + a1(l) * a1(l+1) * ... * a1(r) +
    a1(l) * a1(l+1) * ... * a1(r) * a2(l) + a1(l) * a1(l+1) * ... * a1(r) * a2(l) * a2(l+1) + ... + a1(l) * a1(l+1) * ... * a1(r) * ... * a2(l) * a2(l+1) * ... * a2(r)
  = a.tot + a.mul * b.tot
*/

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Info> a(n);
    for (auto& v : a) {
        int x;
        cin >> x;
        v = {x, x, 1};
    }

    SegTree<Info, Tag> t(a);

    while (q--) {
        int Op, l, r;
        cin >> Op >> l >> r;
        l--, r--;

        if (Op == 1) {
            int x;
            cin >> x;
            t.modify(l, r, Tag(x));
        } else {
            cout << t.query(l, r).tot << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}