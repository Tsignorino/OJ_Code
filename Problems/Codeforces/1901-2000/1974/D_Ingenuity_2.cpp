#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n & 1) {
        cout << "NO\n";
        return;
    }

    map<char, int> mp;
    bool flag = true;
    for (char& ch : s) {
        mp[ch]++;
        if (mp[ch] >= 2) {
            flag = false;
        }
    }

    if (mp['W'] == 1 && mp['E'] == 1 && mp['S'] == 1 && mp['N'] == 1) {
        for (char& ch : s) {
            cout << (ch == 'W' || ch == 'E' ? "H" : "R");
        }
        cout << "\n";
        return;
    }

    if (flag || abs(mp['N'] - mp['S']) & 1 || abs(mp['W'] - mp['E']) & 1) {
        cout << "NO\n";
        return;
    }

    string t("SNWE");
    vector<int> cnt;
    for (char& ch : t) {
        cnt.emplace_back(mp[ch] / 2);
    }
    for (char& ch : s) {
        if (cnt[(int) t.find(ch)]-- > 0) {
            cout << "R";
        } else {
            cout << "H";
        }
    }
    cout << "\n";
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
