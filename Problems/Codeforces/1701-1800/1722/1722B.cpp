#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i] || s1[i] == 'B' && s2[i] == 'G' || s1[i] == 'G' && s2[i] == 'B') {
            continue;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
