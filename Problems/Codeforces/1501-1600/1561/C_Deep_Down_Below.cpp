#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> range(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        //! 进出的力量
        int maxV = -1;
        for (int j = 0; j < k; ++j) {
            int val;
            cin >> val;
            maxV = max(maxV, val - j + 1);
        }
        range[i] = {maxV, k};
    }

    sort(range.begin(), range.end());

    ll ans = 0, power = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, range[i][0] - power); //! 初始力量
        power += range[i][1];
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
