#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    //* 异或
    int ans = 0;
    int num;
    for (int i = 0; i < 3; ++i) {
        cin >> num;
        ans ^= num;
    }

    cout << ans << "\n";

    //* 哈希
    // int a[10] {};
    // int num;
    // for (int i = 0; i < 3; ++i) {
    //     cin >> num;
    //     a[num]++;
    // }

    // int ans = 0;
    // for (int i = 0; i < 10; ++i) {
    //     if (a[i] == 1) {
    //         ans = i;
    //         break;
    //     }
    // }
    // cout << ans << "\n";
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
