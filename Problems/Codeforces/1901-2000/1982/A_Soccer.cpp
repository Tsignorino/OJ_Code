#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // if (a >= b && c <= d || b >= a && d <= c) {
    //     cout << "NO\n";
    // } else {
    //     cout << "YES\n";
    // }

    cout << ((a < b) == (c < d) ? "YES" : "NO") << "\n";
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