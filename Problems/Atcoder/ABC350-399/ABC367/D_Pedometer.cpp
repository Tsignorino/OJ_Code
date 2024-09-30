#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += mp[(pre[i] - pre[n] % k + k) % k];
        ans += mp[pre[i] % k]++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}