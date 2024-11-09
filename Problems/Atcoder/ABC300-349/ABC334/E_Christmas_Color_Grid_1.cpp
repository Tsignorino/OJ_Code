#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 998244353;

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
    template <integral U>
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

    friend constexpr istream& operator>>(istream& in, ModIntBase<T, P>& v) {
        T x;
        in >> x;
        v.x = v.norm(x % T(P));
        return in;
    }
    friend constexpr ostream& operator<<(ostream& os, const ModIntBase& v) { return os << v.val(); }
};

template <uint64_t P>
using ModInt64 = ModIntBase<uint64_t, P>;
using MI = ModInt64<MOD>;

// Attention:
// qpow 模数时，第一个参数应为 MI 类型
// 除数为 MI 类型时，不要连乘

static constexpr int dir[4][2] = {
    {-1, 0 },
    {0,  -1},
    {1,  0 },
    {0,  1 }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    vector id(n, vector<int>(m, -1));
    auto dfs = [&](auto&& dfs, int i, int j) -> void {
        for (int k = 0; k < 4; ++k) {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && vec[ni][nj] == '#' && id[ni][nj] == -1) {
                id[ni][nj] = id[i][j];
                dfs(dfs, ni, nj);
            }
        }
    };

    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == '#' && id[i][j] == -1) {
                id[i][j] = k++;
                dfs(dfs, i, j);
            }
        }
    }

    MI ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == '#') {
                continue;
            }

            cnt++;

            set<int> s;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && vec[ni][nj] == '#') {
                    s.emplace(id[ni][nj]);
                }
            }
            ans -= (int) s.size() - 1;
        }
    }
    cout << ans / cnt + k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}