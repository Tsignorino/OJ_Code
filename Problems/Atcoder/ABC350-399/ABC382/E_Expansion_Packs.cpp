// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<double> p(n + 1);
    p[0] = 1;
    for (int i = 0; i < n; ++i) {
        double val = a[i] / 100.0f;
        for (int j = i; j >= 0; --j) {
            p[j + 1] += p[j] * val;
            p[j] *= 1 - val;
        }
    }

    vector<double> f(x);
    f[0] = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i + j < x) {
                f[i + j] += f[i] * p[j] / (1 - p[0]);
            }
        }
    }
    cout << fixed << setprecision(20) << accumulate(f.begin(), f.end(), 0.0L) / (1 - p[0]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}