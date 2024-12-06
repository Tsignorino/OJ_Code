// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

class ST { // 用于解决可重复贡献问题，需要空间较大
private:
    int n, len;
    function<int(int, int)> Op; // max, min, gcd, 按位 &, 按位 | -> [](int a, int b) { return max(a, b); }
    vector<vector<int>> st;

public:
    explicit ST(int n, function<int(int, int)> Op) : n(n), len(__lg(n)), Op(Op), st(n, vector<int>(len + 1)) {}

    void init(const vector<int>& vec) {
        for (int i = 0; i < n; ++i) {
            st[i][0] = vec[i];
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                st[j][i] = Op(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) { // [l, r]
        int s = __lg(r - l + 1);
        return Op(st[l][s], st[r - (1 << s) + 1][s]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> b(a);
    for (int i = 1; i < n; ++i) {
        b[i] = abs(a[i] - a[i - 1]);
    }

    ST st(n, [&](int a, int b) { return gcd(a, b); });
    st.init(b);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r) {
            cout << 0 << " ";
        } else {
            cout << st.query(l + 1, r) << " ";
        }
    }
    cout << "\n";
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