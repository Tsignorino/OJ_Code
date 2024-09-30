#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        ans += upper_bound(vec.begin() + i + 1, vec.end(), r - vec[i]) - lower_bound(vec.begin() + i + 1, vec.end(), l - vec[i]);
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
