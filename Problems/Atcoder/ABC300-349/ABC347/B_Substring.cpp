#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    set<string> set;
    string s;
    cin >> s;
    int n = s.size();
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < n; ++i) {
            set.insert(s.substr(i, l));
        }
    }

    cout << set.size() << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
