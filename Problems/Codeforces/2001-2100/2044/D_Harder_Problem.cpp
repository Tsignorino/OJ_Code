// Date: 2024-12-16  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> vis(n + 1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (vis[v] == 0) {
            cout << v << " ";
        }
        vis[v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
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