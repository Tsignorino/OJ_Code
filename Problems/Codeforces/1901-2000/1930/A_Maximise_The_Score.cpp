#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n * 2);
    for (int i = 0; i < n * 2; ++i) {
        cin >> vec[i];
    }

    ranges::sort(vec);

    int ans = 0;
    for (int i = 0; i < n * 2; i += 2) {
        ans += vec[i];
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
