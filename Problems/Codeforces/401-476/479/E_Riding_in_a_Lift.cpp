// Date: 2024-12-18  星期三

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

    friend constexpr strong_ordering operator<=>(ModIntBase& lhs, ModIntBase& rhs) { return lhs.val() <=> rhs.val(); }
    friend constexpr bool operator==(ModIntBase& lv, const ModIntBase& rv) { return lv.val() == rv.val(); }

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

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    if (a > b) {
        a = n + 1 - a;
        b = n + 1 - b;
    }

    vector<Mint> f(b), s(b + 1);
    f[a] = 1;
    while (k--) {
        for (int i = 0; i < b; ++i) {
            s[i + 1] = s[i] + f[i];
        }
        for (int y = 1; y < b; ++y) {
            f[y] = s[y + (b - y - 1) / 2 + 1] - f[y];
        }
    }
    cout << accumulate(f.begin(), f.end(), Mint(0)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}