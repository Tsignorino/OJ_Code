// Date: 2024-11-23  星期六

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
    if (n % 2 == 1) {
        cout << "No\n";
        return;
    }

    vector<int> cnt(26);
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == s[i + 1]) {
            cnt[s[i] - 'a'] += 2;
        } else {
            cout << "No\n";
            return;
        }
    }
    for (int& v : cnt) {
        if (v != 0 && v != 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}