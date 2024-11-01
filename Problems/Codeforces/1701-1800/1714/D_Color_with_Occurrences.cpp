#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string t;
    int m;
    cin >> t >> m;
    vector<string> vec(m);
    for (string& s : vec) {
        cin >> s;
    }

    int n = t.size();
    vector<int> f(n + 1);
    vector<pair<int, int>> who(n + 1);
    for (int i = 1; i <= n; ++i) {
        f[i] = 1e9;
        for (int j = 0; j < m; ++j) {
            int len = vec[j].size();
            for (int k = max(i - len, 0); k < i && k <= n - len; ++k) {
                if (t.substr(k, len) == vec[j] && f[k] + 1 < f[i]) {
                    f[i] = f[k] + 1;
                    who[i] = {k, j + 1};
                }
            }
        }
    }

    if (f[n] == 1e9) {
        cout << -1 << "\n";
        return;
    }
    cout << f[n] << "\n";
    int id = n;
    while (who[id].first > 0) {
        cout << format("{} {}\n", who[id].second, who[id].first + 1);
        id = who[id].first;
    }
    cout << format("{} {}\n", who[id].second, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
