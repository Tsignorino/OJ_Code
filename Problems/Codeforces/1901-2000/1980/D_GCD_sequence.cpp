// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    int end = n - 2;
    for (int i = n - 3; i > 0 && gcd(a[i], a[i + 1]) <= gcd(a[i + 1], a[i + 2]); --i) {
        end = i;
    }
    if (end < 2) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n && (i < 3 || gcd(a[i - 3], a[i - 2]) <= gcd(a[i - 2], a[i - 1])); ++i) {
        if (i + 1 >= end && (i == 1 || i == n - 1 || gcd(a[i - 2], a[i - 1]) <= gcd(a[i - 1], a[i + 1])) && (i >= n - 2 || gcd(a[i - 1], a[i + 1]) <= gcd(a[i + 1], a[i + 2]))) {
            cout << "YES\n";
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