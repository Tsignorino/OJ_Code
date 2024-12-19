// Date: 2024-12-19  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 998244353;

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

namespace {
    int SteinGCD(int a, int b) {
        int az = __builtin_ctz(a), bz = __builtin_ctz(b);
        int z = min(az, bz);
        b >>= bz;
        while (a) {
            a >>= az;
            int diff = b - a;
            az = __builtin_ctz(diff);
            if (a < b) {
                b = a;
            }
            a = abs(diff);
        }
        return b << z;
    }
} // namespace

namespace {
    vector<int> primes, vis, lpf, pa;
    void sieve(int N) {
        vis.resize(N + 1);
        lpf.resize(N + 1);
        pa.resize(N + 1);

        for (int i = 2; i <= N; ++i) {
            if (!vis[i]) {
                primes.emplace_back(i);
                lpf[i] = i;
                pa[i] = 1;
            }
            for (int p : primes) {
                if (i * p > N) {
                    break;
                }
                vis[i * p] = 1;
                if (i % p == 0) {
                    lpf[i * p] = lpf[i];
                    pa[i * p] = pa[i];
                    break;
                } else {
                    lpf[i * p] = p;
                    pa[i * p] = i;
                }
            }
        }
    }
    auto init = []() {
        sieve(1e6 + 10);
        return 0;
    }();
    int _gcd(int a, int b) {
        a = abs(a), b = abs(b);
        if (a == 0 || b == 0) {
            return a + b;
        }
        int res = 1;
        while (a != 1 && b != 1) {
            if (lpf[a] == lpf[b]) {
                res *= min(a / pa[a], b / pa[b]);
                a = pa[a];
                b = pa[b];
            } else if (lpf[a] < lpf[b]) {
                a = pa[a];
            } else {
                b = pa[b];
            }
        }
        return res;
    }
} // namespace

void solve() {
    int n;
    cin >> n;

    vector<Mint> a(n);
    for (auto& v : a) {
        cin >> v;
    }

    vector<Mint> b(n);
    for (auto& v : b) {
        cin >> v;
    }

    for (int i = 0; i < n; ++i) {
        Mint ans = 0, m = 1;
        for (int j = 0; j < n; ++j) {
            m *= (i + 1);
            // ans += m * _gcd(a[i].val(), b[j].val());
            ans += m * SteinGCD(a[i].val(), b[j].val());
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}