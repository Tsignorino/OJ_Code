#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    int l = 1, r = 2;
    int ans = 0;
    while (q--) {
        char Op;
        int x;
        cin >> Op >> x;

        if (Op == 'L') {
            if (l < r && x > r) {
                ans += l + n - x;
            } else if (l > r && x < r) {
                ans += n - l + x;
            } else {
                ans += abs(l - x);
            }
            l = x;
        } else {
            if (l < r && x < l) {
                ans += n - r + x;
            } else if (l > r && x > l) {
                ans += r + n - x;
            } else {
                ans += abs(r - x);
            }
            r = x;
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