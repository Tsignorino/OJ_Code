#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ans += abs(num);
    }

    cout << ans << "\n";
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
