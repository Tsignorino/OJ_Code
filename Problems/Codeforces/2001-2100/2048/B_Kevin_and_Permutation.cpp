// Date: 2024-12-20  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n);
    int c = 1;
    for (int i = k - 1; i < n; i += k) {
        ans[i] = c++;
    }
    for (int i = 0; i < n; ++i) {
        cout << (ans[i] == 0 ? c++ : ans[i]) << " \n"[i == n - 1];
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