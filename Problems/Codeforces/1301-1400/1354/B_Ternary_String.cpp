#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = n + 1;
    map<char, int> mp;
    for (int l = 0, r = 0; r < n; ++r) {
        mp[s[r]]++;

        while (mp['1'] && mp['2'] && mp['3']) {
            ans = min(ans, r - l + 1);
            mp[s[l]]--;
            l++;
        }
    }
    cout << (ans == n + 1 ? 0 : ans) << "\n";
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
