#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, s, k;
    cin >> n >> s >> k;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;
        ans += p * q;
    }
    cout << ans + (ans < s ? k : 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}