#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += s[i] == '.';
    }

    for (int i = 0; i < n - 2; ++i) {
        if (s.substr(i, 3) == "...") {
            cout << 2 << "\n";
            return;
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
