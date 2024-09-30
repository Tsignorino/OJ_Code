#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    s.erase(unique(s.begin() + 1, s.end() - 1), s.end() - 1);
    cout << (s == "<=>" ? "Yes" : "No") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
