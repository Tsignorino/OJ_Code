#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && t.back() == '0') {
            continue;
        }
        t.push_back(s[i]);
    }

    cout << (count(t.begin(), t.end(), '1') > count(t.begin(), t.end(), '0') ? "YES" : "NO") << "\n";
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