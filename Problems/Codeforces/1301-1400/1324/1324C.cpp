#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    string ss = 'R' + s + 'R'; // 便于统计
    int pre = 0, ans = 0;
    for (int i = 0; i < ss.size(); ++i) {
        if (ss[i] == 'R') {
            ans = max(ans, i - pre);
            pre = i;
        }
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
