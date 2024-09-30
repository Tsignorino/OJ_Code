#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> a, b;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > t[i]) {
            a.emplace_back(i);
        } else if (s[i] < t[i]) {
            b.emplace_back(i);
        }
    }

    vector<string> ans;
    for (int i : a) {
        s[i] = t[i];
        ans.emplace_back(s);
    }
    for (int i : b | views::reverse) {
        s[i] = t[i];
        ans.emplace_back(s);
    }

    cout << ans.size() << "\n";
    for (string& s : ans) {
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}