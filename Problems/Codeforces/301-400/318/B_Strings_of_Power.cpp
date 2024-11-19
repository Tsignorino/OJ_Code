#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.substr(i, 5) == "heavy") {
            cnt++;
        } else if (s.substr(i, 5) == "metal") {
            ans += cnt;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}