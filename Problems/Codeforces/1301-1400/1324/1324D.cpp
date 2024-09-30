#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        a[i] -= b[i];
    }

    sort(a, a + n);

    long long ans = 0; //* 寻找加和大于 0 的个数
    for (int i = 0; i < n - 1; ++i) {
        ans += n - (upper_bound(a + i + 1, a + n, -a[i]) - a);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
