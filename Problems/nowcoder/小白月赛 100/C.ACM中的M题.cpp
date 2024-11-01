#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        mp[b[i]]++;
    }

    int ans = 0;
    for (auto& [_, c] : mp) {
        if (c == 1) {
            cout << -1 << "\n";
            return;
        }
        ans += (c + 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}