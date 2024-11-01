#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

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

    set<ll> s {0};
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += vec[i];
        if (s.contains(sum)) {
            ans++;
            s.clear();
        }
        s.emplace(sum);
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