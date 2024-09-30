#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    if (n > 45) {
        cout << -1 << "\n";
        return;
    }

    int num = 0, k = 9;
    ll flag = 1;
    while (n) {
        if (n > 0 && n <= k) {
            cout << n * flag + num << "\n";
            return;
        }
        num += k * flag;
        flag *= 10;
        n -= k;
        k--;
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
