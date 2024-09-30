#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //* sol 1:
    int x = 1, y = 0;
    while (x < n && a[x] == a[0]) {
        x++;
    }
    while (y < n && a[n - y - 1] == a[n - 1]) {
        y++;
    }
    int ans = n;
    if (a[0] == a[n - 1]) {
        ans -= x;
        ans -= y;
    } else {
        ans -= max(x, y);
    }
    cout << max(0, ans) << "\n";

    //* sol 2:
    // function<int(int)> func = [&](int v) -> int {
    //     int x = 0, y = n - 1;
    //     while (x < n && a[x] == v) {
    //         x++;
    //     }
    //     while (y > x && a[y] == v) {
    //         y--;
    //     }
    //     return y - x + 1;
    // };

    // cout << min(n - 1, min(func(a[0]), func(a[n - 1]))) << "\n";
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
