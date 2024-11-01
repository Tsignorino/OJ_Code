#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (mp[v]) {
            mp[v]--;
        } else {
            mp[2147483647 ^ v]++;
            ans++;
        }
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
