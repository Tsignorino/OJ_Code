#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    cout << min(n, k) * min(m, k) << "\n";
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