#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i]);
    }
    cout << abs(ans / 2) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
