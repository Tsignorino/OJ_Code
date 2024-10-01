#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n;
    cin >> n;
    n += 2;

    vector<int> a(n);
    for (int i = 1; i < n - 1; i++) {
        cin >> a[i];
    }

    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1] + 1, a[i]);
    }

    vector<int> suf(n);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = min(suf[i + 1] + 1, a[i]);
    }

    // debug(pre);
    // debug(suf);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(pre[i], suf[i]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}