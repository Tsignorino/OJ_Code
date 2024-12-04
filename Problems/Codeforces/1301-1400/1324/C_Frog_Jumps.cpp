// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    s = 'R' + s + 'R';
    int pre = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            ans = max(ans, i - pre);
            pre = i;
        }
    }
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