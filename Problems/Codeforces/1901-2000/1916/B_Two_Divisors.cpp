#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;

    if (b % a == 0) {
        cout << b * 1LL * b / a << "\n";
        return;
    }
    cout << b * 1LL * a / gcd(a, b) << "\n";
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
