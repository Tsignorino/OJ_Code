#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> v0, v1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        (s[i] - '0' == 0 ? v0 : v1).emplace_back(x);
    }

    ranges::sort(v0);
    ranges::sort(v1);

    ll ans = 0;
    for (auto& v : v1) {
        ans += ranges::upper_bound(v0, v + t * 2ll) - ranges::lower_bound(v0, v);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
