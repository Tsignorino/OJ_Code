#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    ranges::sort(l);
    ranges::sort(r);

    ll ans = n * 1ll * (n - 1) / 2;
    for (int i = 0, j = 0; i < n; ++i) {
        for (; j < n && r[j] < l[i]; ++j) {}
        ans -= j;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
