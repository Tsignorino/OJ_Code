#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] < 0) {
            sign *= -1;
        }
        if (a[i] == 0) {
            sign = 0;
        }
    }

    if (sign > 0) {
        cout << 1 << "\n";
        cout << 1 << " " << 0 << "\n";
    } else {
        cout << 0 << "\n";
    }
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
