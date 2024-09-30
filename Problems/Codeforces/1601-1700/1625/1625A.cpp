#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    long long ans = 0;
    for (int i = 0; i < l; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += ((vec[j] >> i) & 1) == 1;
        }

        if (cnt >= n - cnt) {
            ans |= 1 << i;
        }
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
