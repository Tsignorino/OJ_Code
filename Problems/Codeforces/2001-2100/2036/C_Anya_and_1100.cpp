#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += s.substr(i, 4) == "1100";
    }

    int q;
    cin >> q;
    while (q--) {
        int id;
        char ch;
        cin >> id >> ch;
        id--;

        for (int i = max(0, id - 3); i <= id; ++i) {
            ans -= s.substr(i, 4) == "1100";
        }
        s[id] = ch;
        for (int i = max(0, id - 3); i <= id; ++i) {
            ans += s.substr(i, 4) == "1100";
        }
        cout << (ans ? "YES" : "NO") << "\n";
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