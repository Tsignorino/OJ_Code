#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (mp[v]) {
            mp[v]--;
        } else {
            mp[2147483647 ^ v]++;
            ans++;
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
