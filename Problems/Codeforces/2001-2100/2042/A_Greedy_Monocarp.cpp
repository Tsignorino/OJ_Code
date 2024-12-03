// Date: 2024-12-03  星期二

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

    ranges::sort(a, greater<>());

    int sum = 0;
    for (int i = 0; i < n && sum + a[i] <= k; ++i) {
        sum += a[i];
    }
    cout << k - sum << "\n";
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