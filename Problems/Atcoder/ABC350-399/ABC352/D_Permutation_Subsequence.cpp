#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

class ST {
private:
    int n, len;
    function<int(int, int)> Op; // max, min, gcd
    vector<vector<int>> st;

public:
    explicit ST(int n, function<int(int, int)> Op) : n(n), len(__lg(n)), Op(Op) { st.resize(n, vector<int>(len + 1)); }

    void init(vector<int>& vec) {
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
    int n, k;
    cin >> n >> k;
    vector<int> id(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        id[v] = i;
    }

    ST st(n + 1, [](int a, int b) { return max(a, b); });
    st.init(id);
    ST st1(n + 1, [](int a, int b) { return min(a, b); });
    st1.init(id);
    int minV = INT_MAX;
    for (int l = 1, r = l + k - 1; r <= n; ++l, ++r) {
        minV = min(minV, st.query(l, r) - st1.query(l, r));
    }
    cout << minV << "\n";
}

void mysolve() {
    int n, k;
    cin >> n >> k;
    vector<int> id(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        id[v] = i;
    }

    int ans = n + 1;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.emplace(id[i]);
        if (i >= k) {
            ans = min(ans, *s.rbegin() - *s.begin());
            s.erase(id[i - k + 1]);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
