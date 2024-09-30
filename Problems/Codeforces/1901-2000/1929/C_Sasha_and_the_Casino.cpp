#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;

    ll sum = 0;
    for (int i = 0; i <= x; ++i) {
        sum += sum / (k - 1) + 1;
        if (sum > a) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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