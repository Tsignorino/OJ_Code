#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, c;
    cin >> n >> c;

    int pre = -1e5;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (v - pre >= c) {
            ans++;
            pre = v;
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