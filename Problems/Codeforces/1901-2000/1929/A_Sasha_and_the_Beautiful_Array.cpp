#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = 1e9 + 1, mx = 0;
    for (int& v : a) {
        cin >> v;

        mx = max(mx, v), mn = min(mn, v);
    }
    cout << mx - mn << "\n";
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