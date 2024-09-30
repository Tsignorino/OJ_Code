#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    for (int i = 0, j = 0; i < s.size(); ++j) {
        if (s[i] == t[j]) {
            ++i;
            cout << j + 1 << " ";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
