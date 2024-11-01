#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n;
    cin >> n;

    vector<int> l(n, n), r(n, -1);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v--;

        l[v] = min(l[v], i);
        r[v] = max(r[v], i);
    }

    int L = n, R = -1;
    vector<int> diff(n + 1);
    for (int i = 0; i < n; ++i) {
        L = min(L, l[i]), R = max(R, r[i]);
        if (R - L <= i) {
            int p = max(0, R - i), q = min(n - 1, L + i);
            diff[p]++;
            diff[q + 1]--;
        }
    }

    vector<ll> pre(n + 2);
    for (int i = 0; i < n + 1; ++i) {
        pre[i + 1] = pre[i] + diff[i];
    }

    cout << count(pre.begin(), pre.end(), n) << "\n";
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