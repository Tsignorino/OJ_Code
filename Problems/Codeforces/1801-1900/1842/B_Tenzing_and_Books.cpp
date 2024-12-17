// Date: 2024-12-17  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    int ans = 0;
    for (int k = 0; k < 3; ++k) {
        vector<int> a(n);
        for (int& v : a) {
            cin >> v;
        }
        for (int& v : a) {
            if ((x & v) == v) {
                ans |= v;
            } else {
                break;
            }
        }
    }
    cout << (ans == x ? "Yes" : "No") << "\n";
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