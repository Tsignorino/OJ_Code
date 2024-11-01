#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    int cnt = __builtin_popcountll(n);
    if (cnt == 1) {
        cout << format("{}\n{}\n", 1, n);
        return;
    }

    cout << cnt + 1 << "\n";
    for (int i = 63; i >= 0; --i) {
        if (n >> i & 1) {
            cout << (n ^ (1ll << i)) << " ";
        }
    }
    cout << n << "\n";
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