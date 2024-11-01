#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + b[i];
    }

    vector<ll> extra(n + 1);
    vector<ll> diff(n + 1);
    ll p = 0;
    for (int i = 0; i < n; ++i) {
        int id = upper_bound(pre.begin() + i, pre.end(), pre[i] + a[i]) - pre.begin() - 1;
        extra[id] += a[i] - (pre[id] - pre[i]);
        diff[i]++, diff[id]--;
        p += diff[i];
        cout << extra[i] + p * b[i] << " ";
    }
    cout << "\n";
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