#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, x;
    cin >> n >> x;
    x = min(x, n);

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<vector<int>> f(x);
    for (int& v : vec) {
        f[v % x].emplace_back(v);
    }

    for (auto& vec : f) {
        ranges::sort(vec, greater<int>());
    }

    int ans = 0;
    while (!f[ans % x].empty() && f[ans % x].back() <= ans) {
        f[ans % x].pop_back();
        ans++;
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