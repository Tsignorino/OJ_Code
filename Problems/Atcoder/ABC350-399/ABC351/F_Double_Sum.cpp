#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename T>
class Fenwick {
private:
    vector<T> f;
    T Op(T a, T b) { return a + b; } // add, max

public:
    explicit Fenwick(int n) : f(n + 1, 0) {}
    explicit Fenwick(vector<T>& vec) : f(vec.size() + 1) {
        for (int i = 0; i < vec.size(); ++i) {
            add(i + 1, vec[i]);
        }
    }

    void add(int id, T val) { // a[i] += val, i in [1, n]
        for (int i = id; i <= f.size(); i += i & -i) {
            f[i] = Op(f[i], val);
        }
    }

    T query(int id) { // [1, id]
        T res = 0;
        for (int i = id; i > 0; i &= i - 1) { // i -= i & -i
            res += f[i];
        }
        return res;
    }

    T rangeQuery(int l, int r) { return query(r) - query(l - 1); } // [l, r]
};

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) { return vec[i] < vec[j]; });

    Fenwick<ll> f0(n), f1(n);
    ll ans = 0;
    for (int x : id) {
        ll cnt = f0.query(x + 1);
        ll tot = f1.query(x + 1);
        ans += cnt * vec[x] - tot;
        f0.add(x + 1, 1);
        f1.add(x + 1, vec[x]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}