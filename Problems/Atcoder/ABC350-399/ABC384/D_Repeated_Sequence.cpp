// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    ll s;
    cin >> n >> s;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }

    set<ll> S(suf.begin(), suf.end());
    for (int i = 0; i <= n; ++i) {
        if (S.contains((s - pre[i]) % sum)) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}