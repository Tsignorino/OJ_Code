#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int sum = 0, ans = 0, num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
        if (num == 0) {
            ans++;
            sum++; // 0 -> 1
        }
    }
    cout << ans + (sum == 0) << "\n";
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