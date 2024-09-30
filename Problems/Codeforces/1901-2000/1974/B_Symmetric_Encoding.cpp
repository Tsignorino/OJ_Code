#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string t(s);
    ranges::sort(s);
    s.erase(unique(s.begin(), s.end()), s.end());

    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]] = i;
    }
    for (char& ch : t) {
        ch = s[s.size() - mp[ch] - 1];
        // cout << ch << "\n";
    }
    cout << t << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
