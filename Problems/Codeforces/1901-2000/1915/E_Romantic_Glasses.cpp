#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<ll, int> mp;
    ll sum = 0;
    mp[0] = 1;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (i & 1) {
            v = -v;
        }

        sum += v;
        if (mp[sum]) {
            flag = 1;
        }
        mp[sum]++;
    }

    cout << (flag ? "YES" : "NO") << "\n";
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
