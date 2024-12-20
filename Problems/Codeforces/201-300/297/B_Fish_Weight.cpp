// Date: 2024-12-20  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v]++;
    }
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        mp[v]--;
    }

    int pos = 0, neg = 0;
    for (auto& [_, c] : mp | views::reverse) {
        if (c == 0) {
            continue;
        }
        if (c > 0) {
            pos += c;
        } else {
            neg += -c;
        }
        if (pos > neg) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}