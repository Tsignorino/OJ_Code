#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    int d = m - n;
    int cnt = 0;
    for (int i = 0; i < d; ++i) {
        cnt += b[i] - '0';
    }

    ll ans = 0; // !
    for (int i = 0; i < n; ++i) {
        cnt += b[i + d] - '0';

        ans += a[i] == '0' ? cnt : d - cnt + 1;

        cnt -= b[i] - '0';
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
