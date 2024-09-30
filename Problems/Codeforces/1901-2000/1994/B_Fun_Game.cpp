#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            break;
        }
        if (t[i] == '1') {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";

    // mySolve:
    // for (int i = 0; i < n; ++i) {
    //     if (s[i] == '0' && t[i] == '0') {
    //         continue;
    //     }
    //     cout << (s[i] == '0' && t[i] == '1' ? "NO" : "YES") << "\n";
    //     return;
    // }
    // cout << "YES\n";
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