#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> cnt(26);
    for (char ch : s) {
        cnt[ch - 'a']++;
    }
    for (char ch : t) {
        cnt[ch - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] & 1) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                vec.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
            if (s[i] == t[j]) {
                vec.emplace_back(j, j);
                swap(s[j], t[j]);
                vec.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
        }
    }
    cout << vec.size() << "\n";
    for (auto& [a, b] : vec) {
        cout << a + 1 << " " << b + 1 << "\n";
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