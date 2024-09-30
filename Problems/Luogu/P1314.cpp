#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vector<pair<int, int>> vec(n);
    int mn = INT_MAX, mx = INT_MIN;
    for (auto& v : vec) {
        cin >> v.first >> v.second;
        mn = min(mn, v.first);
        mx = max(mx, v.first);
    }
    vector<pair<int, int>> range(m);
    for (auto& v : range) {
        cin >> v.first >> v.second;
    }

    int l = mn - 1, r = mx + 1;
    ll ans = LLONG_MAX;
    ll diff = 0;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        vector<ll> pre_n(n + 1), pre_v(n + 1);
        for (int i = 0; i < n; i++) {
            if (vec[i].first >= mid) {
                pre_n[i + 1] = pre_n[i] + 1;
                pre_v[i + 1] = pre_v[i] + vec[i].second;
            } else {
                pre_n[i + 1] = pre_n[i];
                pre_v[i + 1] = pre_v[i];
            }
        }

        ll tot = 0;
        for (int i = 0; i < m; i++) {
            tot += (pre_n[range[i].second] - pre_n[range[i].first - 1]) * (pre_v[range[i].second] - pre_v[range[i].first - 1]);
        }
        (tot > s ? l : r) = mid;
        ans = min(ans, abs(tot - s));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
