#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    string t;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            t += string(i + 1, 'A');
            t += string(i, 'B');
            ans += 2 * i + 1;
        }
    }
    cout << ans << "\n" << t << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
