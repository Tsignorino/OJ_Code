#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int i = 1;
    while (i < n && s[i] <= t[i - 1]) {
        i++;
    }

    int j = i - 1;
    while (j > 0 && s[j] == t[j - 1]) {
        j--;
    }

    cout << s.substr(0, i) << t.substr(i - 1) << "\n";
    cout << i - j << "\n";
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