#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, w;
    cin >> n >> w;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v]++;
    }

    int ans = 0;
    while (n > 0) {
        ans++;

        int left = w;
        for (int i = 1 << 19; i > 0; i >>= 1) {
            if (mp.contains(i)) {
                int d = min(left / i, mp[i]);
                mp[i] -= d;
                n -= d;
                left -= d * i;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}