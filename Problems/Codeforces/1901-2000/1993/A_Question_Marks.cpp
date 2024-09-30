#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (char ch = 'A'; ch <= 'D'; ++ch) {
        ans += min((int) count(s.begin(), s.end(), ch), n);
    }
    cout << ans << "\n";
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