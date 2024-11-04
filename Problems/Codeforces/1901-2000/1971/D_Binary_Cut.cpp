#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    s.erase(unique(s.begin(), s.end()), s.end());

    cout << s.size() - (s.find("01") != string::npos) << "\n";
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
