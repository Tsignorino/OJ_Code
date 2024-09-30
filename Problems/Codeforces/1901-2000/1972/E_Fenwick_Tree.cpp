#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

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
    constexpr ModIntBase() : x(0) {}
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

template <uint64_t P>
using ModInt64 = ModIntBase<uint64_t, P>;
using MI = ModInt64<MOD>;

struct Combinatorics {
    int n;
    std::vector<MI> _fac, _invfac, _inv;

    Combinatorics() : n {0}, _fac {1}, _invfac {1}, _inv {0} {}
    Combinatorics(int n) : Combinatorics() { init(n); }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    MI fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    MI invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    MI inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    MI comb(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
    MI perm(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(n - m);
    }
} C;

// Attention:
// qpow 模数时，第一个参数应为 MI 类型

void solve() {
    int n, k;
    cin >> n >> k;

    vector<MI> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    vector<MI> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * (k + i - 1) * C.inv(i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int x = i + (i & -i), cnt = 1; x <= n; x += x & -x, cnt++) {
            vec[x] -= f[cnt] * vec[i];
        }
        cout << vec[i] << " \n"[i == n];
    }
}

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