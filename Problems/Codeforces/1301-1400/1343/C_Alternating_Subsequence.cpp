#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    int pre = vec[0];
    int mx = vec[0];
    for (int i = 0; i < n; ++i) {
        if (vec[i] * 1ll * pre > 0) {
            mx = max(mx, vec[i]);
        } else {
            ans += mx;
            pre = vec[i], mx = vec[i];
        }
    }
    ans += mx;

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
