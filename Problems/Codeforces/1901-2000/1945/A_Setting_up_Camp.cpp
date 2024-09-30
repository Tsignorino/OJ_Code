#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int v = b % 3;
    if (v && v + c < 3) {
        cout << -1 << "\n";
        return;
    }

    cout << a + (b + c + 2) / 3 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
