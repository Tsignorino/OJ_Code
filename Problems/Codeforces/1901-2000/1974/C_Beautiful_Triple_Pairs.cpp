#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    //* 容斥
    ll ans = 0;
    for (int x = 0; x < 2; x++) {
        for (int y = x + 1; y < 3; y++) {
            map<std::pair<int, int>, int> cnt;
            for (int i = 0; i + 2 < n; i++) {
                ans += cnt[{vec[i + x], vec[i + y]}]++;
            }
        }
    }

    map<tuple<int, int, int>, int> cnt;
    for (int i = 0; i + 2 < n; i++) {
        ans -= 3 * cnt[{vec[i], vec[i + 1], vec[i + 2]}]++;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
