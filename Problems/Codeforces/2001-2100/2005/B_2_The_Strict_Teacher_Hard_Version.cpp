#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> vec(m);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    while (q--) {
        int v;
        cin >> v;

        auto iter = ranges::lower_bound(vec, v);
        if (iter == vec.begin()) {
            cout << vec.front() - 1 << "\n";
        } else if (iter == vec.end()) {
            cout << n - vec.back() << "\n";
        } else {
            cout << (*iter - *prev(iter)) / 2 << "\n";
        }
    }
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