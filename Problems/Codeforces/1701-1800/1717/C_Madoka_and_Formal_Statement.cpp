#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "NO\n";
            return;
        }

        if (a[i] != b[i] && (b[(i + 1) % n] + 1 < b[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
