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

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1] + 1) {
            swap(a[i], a[i + 1]);
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << "\n";
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