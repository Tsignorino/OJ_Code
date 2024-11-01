#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 == 0) {
        cout << 0 << "\n";
        return;
    }
    if (sum % 3 == 2) {
        cout << 1 << "\n";
        return;
    }
    if (sum % 3 == 1) {
        for (int i = 0; i < n; ++i) {
            if ((sum - a[i]) % 3 == 0) {
                cout << 1 << "\n";
                return;
            }
        }
        cout << 2 << "\n";
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
