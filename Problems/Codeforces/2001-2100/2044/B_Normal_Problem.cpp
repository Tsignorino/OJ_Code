// Date: 2024-12-16  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    for (int i = ssize(s) - 1; i >= 0; --i) {
        if (s[i] == 'p') {
            cout << 'q';
        } else if (s[i] == 'q') {
            cout << 'p';
        } else if (s[i] == 'w') {
            cout << 'w';
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