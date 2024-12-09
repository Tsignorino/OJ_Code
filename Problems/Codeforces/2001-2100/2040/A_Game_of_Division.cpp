// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    for (int i = 0; i < n; ++i) {
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (abs(a[i] - a[j]) % k == 0) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            cout << "YES\n";
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
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