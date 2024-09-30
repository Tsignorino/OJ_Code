#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int odd = 0;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        odd += num & 1;
    }
    int even = n - odd;

    if (odd & 1 || even != 0 && odd) { // “奇数个奇数” 或者 “有偶数有奇数”
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
