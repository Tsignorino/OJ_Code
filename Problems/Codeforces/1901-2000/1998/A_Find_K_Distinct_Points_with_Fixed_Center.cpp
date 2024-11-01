#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> vec;
    if (k & 1) {
        vec.emplace_back(n, m);
        k--;
    }

    for (int i = 1; i <= k / 2; ++i) {
        vec.emplace_back(n - i, m - i);
        vec.emplace_back(n + i, m + i);
    }

    for (auto& [x, y] : vec) {
        cout << x << " " << y << "\n";
    }
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