#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);

    ll ans = numeric_limits<ll>::max();
    for (int k = 0; k < (1 << n); ++k) {
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            if (k >> i & 1) {
                res += vec[i];
            }
        }
        ans = min(ans, max(res, sum - res));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}