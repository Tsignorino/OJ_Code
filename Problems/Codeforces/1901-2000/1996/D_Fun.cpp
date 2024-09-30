#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    // 调和级数
    ll cnt = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; a * b <= n && a + b <= x; ++b) {
            cnt += min((n - a * b) / (a + b), x - a - b);
        }
    }
    cout << cnt << "\n";
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