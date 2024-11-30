// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    ranges::sort(a);

    double ans = 0;
    if (n > 1) {
        ans += accumulate(a.begin(), a.end(), 0ll) * 2;
        ans -= a[0] + a[1];
        ans /= 2;
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}