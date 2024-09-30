#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

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

    void update(int id, int val) { // a[i] += val, 1<=i<=n
        for (int i = id; i <= f.size(); i += i & -i) {
            f[i] = Op(f[i], val);
        }
    }

    int preSum(int id) { // [1, id]
        int res = initVal;
        for (int i = id; i > 0; i &= i - 1) { // i -= i & -i
            res = Op(res, f[i]);
        }
        return res;
    }

    int rangeSum(int l, int r) { return preSum(r) - preSum(l - 1); } // [l, r]
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    Fenwick f(vec);
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            f.update(a, b);
        } else {
            cout << f.rangeSum(a, b) << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
