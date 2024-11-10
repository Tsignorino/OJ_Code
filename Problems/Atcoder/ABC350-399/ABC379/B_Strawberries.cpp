#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (char ch : s) {
        if (ch == 'O') {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt == k) {
            ans++;
            cnt = 0;
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