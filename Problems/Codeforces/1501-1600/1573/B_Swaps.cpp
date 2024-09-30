#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n); // 下标 - 值；值 - 下标
    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        pos[val / 2] = i;
    }

    vector<int> minP(n);
    minP[0] = pos[0];
    for (int i = 1; i < n; ++i) {
        minP[i] = min(minP[i - 1], pos[i]);
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ans = min(ans, i + minP[val / 2 - 1]);
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
