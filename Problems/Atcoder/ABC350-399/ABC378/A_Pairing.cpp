#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    const int N = 4;

    vector<int> cnt(N);
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        v--;
        cnt[v]++;
    }

    int ans = 0;
    for (int& v : cnt) {
        ans += v / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}