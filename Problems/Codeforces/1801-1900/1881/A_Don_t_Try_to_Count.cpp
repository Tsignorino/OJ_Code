#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    string x, s;
    cin >> x >> s;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < n - m + 1; ++j) {
            if (x.substr(j, m) == s) {
                cout << i << "\n";
                return;
            }
        }
        x += x;
        n *= 2;
    }
    cout << "-1\n";
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
