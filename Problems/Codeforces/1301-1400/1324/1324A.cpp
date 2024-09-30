#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    //* 数组中保持奇偶性一致
    int num, sum;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num & 1;
    }

    if (sum == n || sum == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    // int a[n], num;
    // for (int i = 0; i < n; ++i) {
    //     cin >> num;
    //     a[i] = num;
    // }

    // sort(a, a + n);

    // bool flag = true;
    // for (int i = 1; i < n; ++i) {
    //     if ((a[i] - a[i - 1]) & 1) {
    //         flag = false;
    //     }
    // }

    // if (flag) {
    //     cout << "YES\n";
    // } else {
    //     cout << "NO\n";
    // }
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
