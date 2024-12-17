// Date: 2024-12-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> mx(n + 1, numeric_limits<int>::min());
    int f = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        tie(f, mx[v]) = pair(max(f, mx[v] + i + 1), max(mx[v], f - i));
    }
    cout << f << "\n";
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