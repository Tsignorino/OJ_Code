#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            mx1 = max(mx1, vec[i]);
        } else {
            mx2 = max(mx2, vec[i]);
        }
    }
    cout << max((n + 1) / 2 + mx1, n / 2 + mx2) << "\n";
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