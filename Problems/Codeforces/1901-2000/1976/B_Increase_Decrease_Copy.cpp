#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    ll ans = 1; // !
    bool flag = false;
    int mx = -1, mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);

        mn = min({mn, abs(a[i] - b[n]), abs(b[i] - b[n])});
        if ((b[n] - a[i]) * 1ll * (b[n] - b[i]) <= 0) {
            flag = true;
        }
    }

    cout << ans + (flag ? 0 : mn) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
