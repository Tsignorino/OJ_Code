#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (v >= k) {
            res += v;
        } else if (v == 0 && res) {
            ans++;
            res--;
        }
    }
    cout << ans << "\n";
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