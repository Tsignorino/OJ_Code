#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> r(n), c(m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            r[i] += s[j] - '0';
            c[j] += s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            r[i] -= s[j] - '0';
            c[j] -= s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        if (r[i] % 3 != 0) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] % 3 != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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