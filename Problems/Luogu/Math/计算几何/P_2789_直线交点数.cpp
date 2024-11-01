#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> f(10010);

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    auto dfs = [&](auto&& dfs, int x, int t) -> void {
        if (x == 0) {
            if (f[t] == 0) {
                f[t] = 1;
                ans++;
            }
        } else {
            for (int r = x; r >= 1; --r) {
                dfs(dfs, x - r, r * (x - r) + t);
            }
        }
    };

    dfs(dfs, n, 0);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}