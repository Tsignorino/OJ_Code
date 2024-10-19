#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/89510/B
*/

void solve() {
    string s;
    cin >> s;

    string ss(s);
    ranges::sort(ss, greater<>());

    cout << (s == ss ? "NO" : "YES") << "\n";
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