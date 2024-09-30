#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    int res = n;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;

        res = min(res, r - l + 1);
    }

    cout << res << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i % res << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
