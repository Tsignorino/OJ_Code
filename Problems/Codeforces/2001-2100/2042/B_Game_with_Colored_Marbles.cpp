// Date: 2024-12-03  星期二

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
    map<int, int> d;
    for (int& v : a) {
        cin >> v;
        d[v]++;
    }

    int cnt = 0;
    for (auto& [_, c] : d) {
        if (c == 1) {
            cnt++;
        }
    }

    int ans = d.size() - cnt;
    ans += (cnt + 1) / 2 * 2;
    cout << ans << "\n";
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