// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    k--;

    if (bit_width(k * 1ull) >= n) {
        cout << -1 << "\n";
        return;
    }

    vector<int> ans(n);
    int x = 1, p = 0, q = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (i > 60 || k < (1ll << i)) {
            ans[p++] = x;
        } else {
            ans[q--] = x;
            k -= (1ll << i);
        }
        x++;
    }
    assert(p == q);
    ans[p] = x;
    for (int& v : ans) {
        cout << v << " ";
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