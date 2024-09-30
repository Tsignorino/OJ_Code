#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + p[i];
    }

    ll sum = pre[n];

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        auto c1 = ranges::upper_bound(x, r) - x.begin() - 1;
        auto c2 = ranges::lower_bound(x, l) - x.begin();
        // cout << "debug:" << c1 << " " << c2 << "\n";
        cout << pre[c1 + 1] - pre[c2] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}