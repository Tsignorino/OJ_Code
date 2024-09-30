#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // substr(idx, n)
    for (int i = 0; i <= 4; ++i) {
        if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
