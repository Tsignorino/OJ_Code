#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e8 - 3;

class Fenwick {
    int initVal = 0;
    vector<int> f;
    int Op(int a, int b) { return a + b; } // add, max

public:
    explicit Fenwick(int n) : f(n + 1, initVal) {}
    explicit Fenwick(vector<int>& vec) : f(vec.size() + 1) {
        for (int i = 0; i < vec.size(); ++i) {
            update(i + 1, vec[i]);
        }
    }

    void update(int id, int val) {
        for (int i = id; i <= f.size(); i += i & -i) {
            f[i] = Op(f[i], val);
        }
    }

    int preSum(int id) { // [1, id]
        int res = initVal;
        for (int i = id; i > 0; i &= i - 1) { // i -= i & -i
            res += f[i];
        }
        return res;
    }

    int rangeSum(int l, int r) { return preSum(r) - preSum(l - 1); } // [l, r]
};

void solve() {
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int& v : v1) {
        cin >> v;
    }
    for (int& v : v2) {
        cin >> v;
    }

    /*
        每次交换相邻两根火柴
    */

    vector<int> tmp = v1;
    ranges::sort(tmp);
    for (int& v : v1) {
        v = ranges::lower_bound(tmp, v) - tmp.begin();
    }

    // 将 v1 离散化的结果作为标准
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        idx[v1[i]] = i;
    }

    tmp = v2;
    ranges::sort(tmp);
    for (int& v : v2) {
        v = idx[ranges::lower_bound(tmp, v) - tmp.begin()];
    }

    // 求 v2 的逆序对
    Fenwick f(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        f.update(v2[i] + 1, 1);
        ans += i + 1 - f.preSum(v2[i] + 1);
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
