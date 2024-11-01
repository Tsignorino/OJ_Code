#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    ll x = 0, y = 0;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ll nx, ny;
        cin >> nx >> ny;
        ans += hypot(abs(nx - x), abs(ny - y));
        x = nx, y = ny;
    }
    cout << fixed << setprecision(20) << ans + hypot(x, y) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}