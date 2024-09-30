#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

const vector<vector<int>> ans {
    {},
    {1},
    {1, 2},
    {1, 2, 2},
    {1, 2, 2, 3},
    {1, 2, 2, 3, 3}
};

void solve() {
    int n;
    cin >> n;

    if (n <= 5) {
        cout << ranges::max(ans[n]) << "\n";
        for (int i = 0; i < n; i++) {
            cout << ans[n][i] << " ";
        }
    } else {
        cout << 4 << "\n";
        for (int i = 0; i < n; i++) {
            cout << i % 4 + 1 << " ";
        }
    }
    cout << "\n";
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
