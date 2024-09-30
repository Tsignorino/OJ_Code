#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
    }

    map<int, ll> mp {
        {0, 1}
    };
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (n - i + 1) * mp[pre[i]] % MOD;
        ans %= MOD;
        mp[pre[i]] += i + 1;
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