// Date: 2024-11-30  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    ranges::sort(a);
    a.erase(unique(a.begin(), a.end()), a.end());

    int ans = 0;
    for (int l = 0, r = 0; r < a.size(); ++r) {
        while (a[r] - a[l] - 1 - (r - l - 1) > k) {
            l++;
        }
        ans = max(ans, min(m, r - l + 1 + k));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}