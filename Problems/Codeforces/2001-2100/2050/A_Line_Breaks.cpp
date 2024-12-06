// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = s.size();
    }

    int i = 0;
    while (i < n && m >= a[i]) {
        m -= a[i];
        i++;
    }
    cout << i << "\n";
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