#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int i = 0;
    while (i < min(n, m) && s[i] == t[i]) {
        i++;
    }
    cout << n + m - i + (i != 0) << "\n";
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