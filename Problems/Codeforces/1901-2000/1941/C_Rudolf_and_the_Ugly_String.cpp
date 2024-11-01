#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") {
            i += 2;
            cnt++;
        }
    }

    cout << cnt << "\n";
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
