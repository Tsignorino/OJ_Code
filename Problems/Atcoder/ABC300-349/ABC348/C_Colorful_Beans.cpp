#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (mp[b]) {
            mp[b] = min(mp[b], a);
        } else {
            mp[b] = a;
        }
    }

    int ans = 0;
    for (auto& [id, cnt] : mp) {
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
