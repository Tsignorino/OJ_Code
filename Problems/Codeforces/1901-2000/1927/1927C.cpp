#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    int a[n], b[m];
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            cnt[a[i]] |= 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] <= k) {
            cnt[b[i]] |= 2;
        }
    }

    int v[4] {}; // v[1] 只出现在 a，v[2] 只出现在 b，v[3] 两个都有
    for (const auto& [_, c] : cnt) {
        v[c]++;
    }

    if (v[1] * 2LL > k || v[2] * 2LL > k || v[1] * 1LL + v[2] + v[3] != k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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