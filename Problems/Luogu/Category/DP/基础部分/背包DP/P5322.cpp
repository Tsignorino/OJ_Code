#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int s, n, m;
    cin >> s >> n >> m;

    vector vec(n + 1, vector<int>(s + 1));
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> vec[j][i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        ranges::sort(vec[i]);
    }

    vector<int> dp(m + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            for (int k = 1; k <= s; ++k) {
                if (j > vec[i][k] * 2) {
                    dp[j] = max(dp[j], dp[j - vec[i][k] * 2 - 1] + k * i);
                }
            }
        }
    }

    cout << ranges::max(dp) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}