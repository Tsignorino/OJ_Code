#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    bool flag = (s[0] == 'B' || s[n - 1] == 'B');
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1] && s[i] == 'B') {
            flag = true;
        }
    }

    vector<int> lengths;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            cur++;
        } else {
            if (cur) {
                lengths.emplace_back(cur);
            }
            cur = 0;
        }
    }
    if (cur) {
        lengths.emplace_back(cur);
    }

    if (lengths.empty()) {
        cout << 0 << "\n";
        return;
    }

    sort(lengths.begin(), lengths.end());

    int total = 0;
    if (flag) {
        total += lengths[0];
    }
    for (int i = 1; i < lengths.size(); ++i) {
        total += lengths[i];
    }

    cout << total << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
