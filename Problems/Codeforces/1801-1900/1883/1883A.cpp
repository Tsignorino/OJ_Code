#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int pre = 1, ans = 4;
    for (int i = 0; i < 4; ++i) {
        int v = s[i] - '0' == 0 ? 10 : s[i] - '0';
        ans += abs(v - pre);
        pre = v;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
