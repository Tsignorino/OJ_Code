#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

template <typename T>
constexpr T qpow(T x, uint64_t k) {
    T res = 1;
    for (; k; k >>= 1) {
        if (k & 1) {
            res *= x;
        }
        x *= x;
    }
    return res;
}

template <uint64_t P>
constexpr uint64_t mulMod(uint64_t a, uint64_t b) {
    return a * 1ull * b % P;
}

template <typename T, T P>
class ModIntBase {
private:
    T x;

public:
    template <std::integral U>
    constexpr ModIntBase(U x_ = 0) : x(norm(x_ % U(P))) {}

    constexpr T norm(T x) {
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
    constexpr ModIntBase& operator*=(const ModIntBase& rv) & { return *this = mulMod<P>(x, rv.val()); }
    constexpr ModIntBase& operator+=(const ModIntBase& rv) & { return *this = norm(x + rv.x); }
    constexpr ModIntBase& operator-=(const ModIntBase& rv) & { return *this = norm(x - rv.x); }
    constexpr ModIntBase& operator/=(const ModIntBase& rv) & { return *this *= rv.inv(); }
    constexpr ModIntBase& operator++() & { return x = norm(x + 1), *this; }
    constexpr ModIntBase& operator--() & { return x = norm(x - 1), *this; }
    constexpr ModIntBase operator++(int) { // 后置
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
    friend constexpr bool operator<(ModIntBase lv, const ModIntBase rv) { return lv.val() < rv.val(); }
    friend constexpr bool operator==(ModIntBase lv, const ModIntBase rv) { return lv.val() == rv.val(); }
    friend constexpr bool operator!=(ModIntBase lv, const ModIntBase rv) { return lv.val() != rv.val(); }

    friend constexpr std::istream& operator>>(std::istream& in, ModIntBase<T, P>& v) {
        T x;
        in >> x;
        v.x = v.norm(x % T(P));
        return in;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const ModIntBase& v) { return os << v.val(); }
};

template <uint32_t P>
using ModInt = ModIntBase<uint32_t, P>;
template <uint64_t P>
using ModInt64 = ModIntBase<uint64_t, P>;

constexpr uint32_t P1 = 998244353;
constexpr uint32_t P2 = 1'000'000'007;
// using MI = ModInt<P1>;
using MI = ModInt64<P1>;

// Attention:
// qpow 模数时，第一个参数应为 MI 类型

struct Tag {
    MI addA = 0, addB = 0;
    void apply(const Tag& t) { addA += t.addA, addB += t.addB; }
};

struct Info {
    MI sA = 0, sB = 0, sAB = 0, len = 1;

    void apply(const Tag& t) {
        sA += len * t.addA;
        sAB += t.addA * sB;
        sB += len * t.addB;
        sAB += t.addB * sA;
    }
};
Info operator+(const Info& a, const Info& b) {
    return Info(a.sA + b.sA, a.sB + b.sB, a.sAB + b.sAB, a.len + b.len);
}

class SegTree {
private:
    ll n;
    vector<Tag> tag;
    vector<Info> info;

    void apply(ll o, const Tag& t) { tag[o].apply(t), info[o].apply(t); }
    void push_up(ll o) { info[o] = info[o << 1] + info[o << 1 | 1]; }
    void push_down(ll o) { apply(o << 1, tag[o]), apply(o << 1 | 1, tag[o]), tag[o] = Tag(); }

    void update(ll todol, ll todor, ll o, ll l, ll r, const Tag& t) {
        if (todor < l || r < todol) return;
        if (todol <= l && r <= todor) {
            apply(o, t);
            return;
        }
        push_down(o);
        ll m = l + (r - l) / 2;
        update(todol, todor, o << 1, l, m, t);
        update(todol, todor, o << 1 | 1, m + 1, r, t);
        push_up(o);
    }

    Info query(ll todol, ll todor, ll o, ll l, ll r) {
        if (todor < l || r < todol) return Info();
        if (todol <= l && r <= todor) return info[o];
        push_down(o);
        ll m = l + (r - l) / 2;
        return query(todol, todor, o << 1, l, m) + query(todol, todor, o << 1 | 1, m + 1, r);
    }

public:
    SegTree() {}
    SegTree(ll n) : n(n), tag(4 * n), info(4 * n) {} // 4 << __lg(n)
    SegTree(const vector<Info>& init) : SegTree(init.size()) {
        auto build = [&](auto&& self, ll o, ll l, ll r) -> void {
            if (l == r) {
                info[o] = init[l];
                return;
            }
            ll m = l + (r - l) / 2;
            self(self, o << 1, l, m);
            self(self, o << 1 | 1, m + 1, r);
            push_up(o);
        };
        build(build, 1, 1, n);
    }

    void update(ll todol, ll todor, const Tag& t) { update(todol, todor, 1, 1, n, t); }
    Info query(ll todol, ll todor) { return query(todol, todor, 1, 1, n); }
};
// Info 下标从 1开始

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Info> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i].sA;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i].sB;
        vec[i].sAB = vec[i].sA * vec[i].sB;
    }

    SegTree tree(vec);

    while (q--) {
        int Op, l, r;
        cin >> Op >> l >> r;

        if (Op == 3) {
            cout << tree.query(l, r).sAB << "\n";
        } else {
            int x;
            cin >> x;
            if (Op == 1) {
                tree.update(l, r, Tag(x, 0));
            } else {
                tree.update(l, r, Tag(0, x));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}