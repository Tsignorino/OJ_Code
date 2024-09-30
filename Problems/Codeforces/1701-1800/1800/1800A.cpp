#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    int n;
    cin >> n >> s;

    ranges::transform(s, s.begin(), [](char c) { return tolower(c); });
    s.erase(unique(s.begin(), s.end()), s.end());

    cout << (s == "meow" ? "YES\n" : "NO\n");
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
