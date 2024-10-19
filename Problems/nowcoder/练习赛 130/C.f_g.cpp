#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 998244353;

template <typename T>
constexpr T qpow(T x, uint64_t a) {
    T res = 1;
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

    friend constexpr bool operator<(ModIntBase lv, const ModIntBase rv) { return lv.val() < rv.val(); }
    friend constexpr bool operator==(ModIntBase lv, const ModIntBase rv) { return lv.val() == rv.val(); }
    friend constexpr bool operator!=(ModIntBase lv, const ModIntBase rv) { return lv.val() != rv.val(); }

    friend constexpr istream& operator>>(istream& in, ModIntBase<T, P>& v) {
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

using MI = ModInt32<MOD>;

template <typename T>
class Fenwick {
public:
    int n;
    vector<T> nums, tree;

    void update(int id, T val) {
        for (int i = id + 1; i <= n; i += i & -i) {
            tree[i - 1] += val;
        }
    }

public:
    explicit Fenwick(int n) : n(n), nums(n), tree(n) {}
    template <typename U>
    explicit Fenwick(const vector<U>& nums) : Fenwick(nums.size()) {
        for (int i = 0; i < n; ++i) {
            this->nums[i] = nums[i];
            update(i, nums[i]);
        }
    }

    void add(int id, T val) {
        update(id, val);
        nums[id] += val;
    }
    void modify(int id, T x) {
        add(id, x - nums[id]);
        nums[id] = x;
    }
    T preSum(int id) {
        T ans = 0;
        for (int i = id + 1; i > 0; i &= i - 1) {
            ans += tree[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) { return preSum(r) - preSum(l - 1); }
};
// The Fenwick is aligned with the input array 0-index and the modifications are not independent.

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> f(n), g(n);
    for (int& v : f) {
        cin >> v;
    }
    for (int& v : g) {
        cin >> v;
    }

    Fenwick<MI> F(f), G(g);
    MI v = 0;
    for (int i = 0; i < n; ++i) {
        v += G.nums[i] * F.preSum(i) + F.nums[i] * G.rangeSum(i + 1, n - 1);
    }
    // cout << v << "\n";

    while (q--) {
        int Op, i, x;
        cin >> Op >> i >> x;
        i--;

        if (Op == 1) {
            v += (x - F.nums[i]) * (2 * G.rangeSum(i + 1, n - 1) + G.nums[i]);
            F.modify(i, x);
        } else {
            v += (x - G.nums[i]) * (2 * F.preSum(i) - F.nums[i]);
            G.modify(i, x);
        }
        cout << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}