#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) { return a[i] + b[i] < a[j] + b[j]; });

    for (int& i : id) {
        cout << a[i] << " " << b[i] << " ";
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