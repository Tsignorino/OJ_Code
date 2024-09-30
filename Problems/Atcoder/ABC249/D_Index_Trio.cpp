#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;
static constexpr int MX = 2e5;

void solve() {
    int n;
    cin >> n;

    vector<int> res(MX);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        res[val]++;
    }

    ll ans = 0;
    for (int i = 1; i <= MX; ++i) {
        for (int j = 1; i * j <= MX; ++j) {
            ans += res[i] * 1ll * res[j] * res[i * j];
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