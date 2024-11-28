// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] / b[i];
    }

    vector<ll> suf {0};
    for (int i = n - 1; i >= 0; --i) {
        suf.emplace_back(suf.back() + c[i]);
    }

    ranges::reverse(suf);

    vector<int> res(n);
    if (suf[0] >= k) {
        for (int i = 0; i < n; ++i) {
            ll v = max(k - suf[i + 1], 0ll);
            k -= v;
            res[i] = v;
        }
    }
    for (int& v : res) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}