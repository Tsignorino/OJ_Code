#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < n && j < m; ++i) {
        if (s[i] == t[j] || s[i] == '?') {
            s[i] = t[j];
            j++;
        }
    }
    if (j == m) {
        cout << "YES\n";
        replace(s.begin(), s.end(), '?', 'a');
        cout << s << "\n";
    } else {
        cout << "NO\n";
    }
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