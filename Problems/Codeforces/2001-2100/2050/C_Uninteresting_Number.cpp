// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> a(n), b;
    array<int, 2> c {}; // 2, 6
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        if (a[i] == 2) {
            c[0]++;
        } else if (a[i] == 3) {
            c[1]++;
        }
    }
    c[0] = min(c[0], 8);
    c[1] = min(c[1], 2);

    int v = accumulate(a.begin(), a.end(), 0) % 9;
    // debug(c, v);
    if (v == 0) {
        cout << "YES\n";
    } else {
        for (int i = 0; i <= c[0]; ++i) {
            for (int j = 0; j <= c[1]; ++j) {
                int tmp = (v + i * 2 + j * 6) % 9;
                if (tmp == 0) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
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