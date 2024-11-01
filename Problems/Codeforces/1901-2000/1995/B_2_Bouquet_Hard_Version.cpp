#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].second;
    }

    ranges::sort(vec);

    vec.emplace_back(pair<ll, ll>());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, min(m / vec[i].first, vec[i].second) * vec[i].first);

        // x * a + y * (a + 1)
        if (vec[i + 1].first - vec[i].first == 1) {
            ll val = 0;
            if (vec[i].first * vec[i].second >= m) {
                val = m / vec[i].first;
            } else {
                val = vec[i].second + min((m - vec[i].first * vec[i].second) / vec[i + 1].first, vec[i + 1].second);
            }
            ans = max(ans, min(m, val * vec[i].first + min(val, vec[i + 1].second)));
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