// Date: 2024-12-21  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    if (s.front() == '.') {
        s.front() = 's';
    }
    if (s.back() == '.') {
        s.back() = 'p';
    }

    int ok = count(s.begin(), s.end(), 'p') <= 1 || count(s.begin(), s.end(), 's') <= 1;
    s.erase(remove(s.begin(), s.end(), '.'), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if (ok && (s == "sp" || s == "s" || s == "p")) {
        cout << "YES\n";
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