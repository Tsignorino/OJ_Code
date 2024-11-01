#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v1(n), v2(m);
    for (int& v : v1) {
        cin >> v;
    }

    for (int& v : v2) {
        cin >> v;
    }

    sort(v2.begin(), v2.end());

    ll cnt = 0;
    for (int& v : v1) {
        cnt += upper_bound(v2.begin(), v2.end(), k - v) - v2.begin();
    }

    cout << cnt << "\n";
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
