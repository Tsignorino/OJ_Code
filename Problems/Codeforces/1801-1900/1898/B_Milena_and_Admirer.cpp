#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (vec[i] <= vec[i + 1]) {
            continue;
        }

        // while (vec[i] > vec[i + 1]) {
        //     if ((vec[i] + 1) / 2 > vec[i + 1]) {
        //         vec[i] -= vec[i + 1];
        //     } else {
        //         vec[i] /= 2;
        //     }
        //     ans++;
        // }

        int k = (vec[i] + vec[i + 1] - 1) / vec[i + 1];
        vec[i] /= k;
        ans += k - 1;
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