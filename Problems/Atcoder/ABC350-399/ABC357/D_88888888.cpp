#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace MI_space {
    using ll = long long;
    const ll pmod = 998244353;

    struct MI;
    MI inv(MI a);
    ll exgcd(ll a, ll b, ll& x, ll& y);
    MI qpow(MI a, MI b, MI p);

    struct MI {
        ll val;
        MI() { val = 0; }
        MI(ll a) { val = (a % pmod + pmod) % pmod; }
        MI(int a) { val = (a % pmod + pmod) % pmod; }
        friend MI operator+(const MI& a, const MI& b) { return (a.val + b.val) % pmod; }
        friend MI operator-(const MI& a, const MI& b) { return (a.val - b.val + pmod) % pmod; }
        friend MI operator*(const MI& a, const MI& b) { return (a.val * b.val) % pmod; }
        friend MI operator/(const MI& a, const MI& b) { return (a.val * inv(b.val)).val % pmod; }
        friend MI& operator+=(MI& a, const MI& b) { return a = a + b; }
        friend MI& operator-=(MI& a, const MI& b) { return a = a - b; }
        friend MI& operator*=(MI& a, const MI& b) { return a = a * b; }
        friend MI& operator/=(MI& a, const MI& b) { return a = a / b; }
    };

    MI inv(MI a) {
        ll x, y;
        exgcd(a.val, pmod, x, y);
        x = (x % pmod + pmod) % pmod;
        return x;
    }
    MI qpow(MI a, ll b) {
        MI ans = 1;
        for (; b; b >>= 1, a *= a)
            if (b & 1) ans *= a;
        return ans;
    }
    ll exgcd(ll a, ll b, ll& x, ll& y) {
        if (b == 0) {
            return x = 1, y = 0, a;
        }
        ll d = exgcd(b, a % b, x, y);
        ll z = x;
        x = y;
        y = z - (a / b) * y;
        return d;
    }

#ifdef _GLIBCXX_IOSTREAM
    std::istream& operator>>(std::istream& cin, MI& a) {
        cin >> a.val;
        a.val %= pmod;
        return cin;
    }
    std::ostream& operator<<(std::ostream& cout, MI a) {
        cout << a.val;
        return cout;
    }
#endif
} // namespace MI_space
using namespace MI_space;

void solve() {
    ll x;
    cin >> x;

    ll n = to_string(x).size();
    ll res = 1, cnt = 0;

    while (cnt < n) {
        res *= 10;
        cnt++;
    }
    
    // x * 10^(nx) + x * 10^(n(x-1)) + ... + x = x * q(10^n)
    cout << (MI) x * (qpow(res, x) - 1) / (qpow(10, n) - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
