#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    // int cnt0 = 0, sum = 0, num;
    // for (int i = 0; i < n; ++i) {
    //     cin >> num;
    //     cnt0 += num == 0; // 0 的个数
    //     sum += num;
    // }

    // if (cnt0 != 0) {
    //     cout << cnt0 + (sum + cnt0 == 0) << "\n";
    // } else {
    //     cout << (sum == 0) << "\n";
    // }

    int sum = 0, ans = 0, num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;

        if (num == 0) {
            ans++;
            sum++; // 0 -> 1
        }
    }

    cout << ans + (sum == 0) << "\n";
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
