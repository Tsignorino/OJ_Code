#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> w(n), x(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> x[i];
    }

    int ans = 0;
    for (int k = 0; k < 24; ++k) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int t = (x[i] + k) % 24;
            if (t >= 9 && t <= 17) {
                res += w[i];
            }
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}