#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n;
    cin >> n;

    const int N = 1e6;
    vector<ll> cnt(N + 1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        cnt[v]++;
    }

    for (int i = 0; i < N; ++i) {
        cnt[i + 1] += cnt[i];
    }
    // debug(cnt);

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ll d = cnt[i] - cnt[i - 1];
        for (int j = i; j <= N; j += i) {
            ans += j / i * (cnt[min(N, j + i - 1)] - cnt[j - 1]) * d;
        }
        ans -= d * (d + 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}