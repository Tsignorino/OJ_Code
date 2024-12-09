// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> b(m);
    for (int& v : b) {
        cin >> v;
    }

    ranges::sort(a);
    ranges::sort(b);

    auto check = [&](auto x) {
        // int v = ranges::upper_bound(a, x) - a.begin();
        // int u = b.end() - ranges::lower_bound(b, x);
        // cout << v << " " << u << "\n";
        return ranges::upper_bound(a, x) - a.begin() >= b.end() - ranges::lower_bound(b, x);
    };

    int lo = 0, hi = 1e9 + 1;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}