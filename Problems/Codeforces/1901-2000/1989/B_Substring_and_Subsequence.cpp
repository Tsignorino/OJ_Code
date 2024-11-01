#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string a, b;
    cin >> a >> b;

    int m = a.size(), n = b.size();
    int mx = 0;
    for (int j = 0; j < n; ++j) {
        int p = j;
        for (int i = 0; i < m; ++i) {
            if (p < n && a[i] == b[p]) {
                p++;
            }
        }
        mx = max(mx, p - j);
    }
    cout << m + n - mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
