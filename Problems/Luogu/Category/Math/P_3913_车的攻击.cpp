#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int N, n;
    cin >> N >> n;

    vector<int> r(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i];
    }

    ranges::sort(r);
    ranges::sort(c);

    r.erase(unique(r.begin(), r.end()), r.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    cout << (N * 1ll * N - (N - r.size()) * (N - c.size())) << "\n";

    // set<int> R, C;
    // ll ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (!R.contains(r[i])) {
    //         ans += N - C.size();
    //         R.emplace(r[i]);
    //     }
    //     if (!C.contains(c[i])) {
    //         ans += N - R.size();
    //         C.emplace(c[i]);
    //     }
    // }
    // cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}