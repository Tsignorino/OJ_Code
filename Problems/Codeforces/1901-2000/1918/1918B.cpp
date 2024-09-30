#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 对于相同的两个索引同时操作，逆序数可能由 0 变为 2，由 1 变为 1，由 2 变为 0
// 因此，当其中一个已排序，此时反转总数最小
void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> ans[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> ans[i].second;
    }

    ranges::sort(ans);

    for (int i = 0; i < n; ++i) {
        cout << ans[i].first << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].second << " \n"[i == n - 1];
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
