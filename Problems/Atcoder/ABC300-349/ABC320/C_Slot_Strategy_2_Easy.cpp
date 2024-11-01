#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int m;
    cin >> m;

    const int n = 3;
    vector<string> S(n);
    for (string& v : S) {
        cin >> v;
    }

    int ans = 1e9;
    for (int i = 0; i < n * m; ++i) {
        for (int j = 0; j < n * m; ++j) {
            for (int k = 0; k < n * m; ++k) {
                if (i != j && j != k && i != k && S[0][i % m] == S[1][j % m] && S[0][i % m] == S[2][k % m]) {
                    ans = min(ans, max({i, j, k}));
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}