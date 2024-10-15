#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    int maxV = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ans += a;
        maxV = max(maxV, b - a);
    }

    cout << ans + maxV << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
