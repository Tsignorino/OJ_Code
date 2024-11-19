#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    for (int& v : h) {
        cin >> v;
    }

    vector<int> x(n);
    for (int& v : x) {
        cin >> v;
    }

    auto check = [&](auto mid) {
        map<int, int> d;
        for (int i = 0; i < n; ++i) {
            int v = (h[i] + mid - 1) / mid;
            if (v <= m) {
                d[x[i] - (m - v)]++;
                d[x[i] + (m - v) + 1]--;
            }
        }

        int s = 0;
        for (auto& [_, v] : d) {
            s += v;
            if (s >= k) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = 1e9 + 10;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << (hi == 1e9 + 10 ? -1 : hi) << "\n";
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