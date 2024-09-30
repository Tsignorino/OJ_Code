#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;
    int a[n], sum;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int avg = sum / n;
    for (int i = 0; i < n; ++i) {
        if (a[i] < avg) {
            cout << "NO\n";
            return;
        }
        a[i + 1] += a[i] - avg;
    }

    cout << "YES\n";
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
