#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n < m) {
        cout << 0 << "\n";
        return;
    }

    vector<int> a(n), b(m);
    map<int, int> cnt;
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
        cnt[v]++;
    }

    map<int, int> cnt1;
    int l = 0, r = 0;
    ll res = 0;
    for (; r < m; ++r) {
        res += cnt1[a[r]] < cnt[a[r]];
        cnt1[a[r]]++;
    }
    ll ans = res >= k;
    for (; r < n; ++r) {
        res += cnt1[a[r]] < cnt[a[r]];
        cnt1[a[r]]++;

        res -= cnt1[a[l]] <= cnt[a[l]];
        cnt1[a[l++]]--;

        ans += res >= k;
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