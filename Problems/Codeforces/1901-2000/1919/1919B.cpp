#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int diff = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '-') {
            diff -= 1;
        } else {
            diff += 1;
        }
    }

    cout << abs(diff) << "\n";
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
