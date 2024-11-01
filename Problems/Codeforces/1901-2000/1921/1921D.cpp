#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a1(n), a2(m);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a2[i];
    }

    sort(a1.rbegin(), a1.rend());
    sort(a2.begin(), a2.end());

    //* 定长滑窗
    long long diff = 0;
    for (int i = 0; i < n; ++i) {
        diff += abs(a1[i] - a2[i]);
    }

    long long ans = diff;
    for (int i = n - 1, r = m - 1; i >= 0; --i, --r) {
        diff += abs(a1[i] - a2[r]);
        diff -= abs(a1[i] - a2[i]);

        ans = max(ans, diff);
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
