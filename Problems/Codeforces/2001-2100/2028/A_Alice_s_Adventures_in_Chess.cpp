#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int x = 0, y = 0;
    for (int k = 0; k <= 15; ++k) {
        for (char ch : s) {
            if (ch == 'N') {
                y++;
            } else if (ch == 'W') {
                x--;
            } else if (ch == 'E') {
                x++;
            } else {
                y--;
            }
            if (x == a && y == b) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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