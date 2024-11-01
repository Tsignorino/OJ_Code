#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        ans += val / 5 * 3;
        val %= 5;
        while (val > 0) {
            ans++;
            if (ans % 3 == 0) {
                val -= 3;
            } else {
                val--;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}