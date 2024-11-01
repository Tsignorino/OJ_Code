#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    int mx = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        mx = max(mx, val);
        sum += val;
        if (mx * 2 == sum) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
