// Date: 2024-12-06  星期五

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

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (sum % n) {
        cout << "NO\n";
    } else {
        int v = sum / n;
        for (int i = 0; i < n - 2; ++i) {
            int d = a[i] - v;
            a[i + 2] += d;
        }
        cout << (a[n - 1] == v && a[n - 2] == v ? "YES" : "NO") << "\n";
    }
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