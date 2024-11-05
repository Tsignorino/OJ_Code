#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (auto& s : vec) {
        cin >> s;
    }

    const string s = "narek";

    vector<array<int, 5>> f(n + 1);
    for (int i = 0; i < 5; ++i) {
        f.back()[i] = -i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c < 5; ++c) {
            f[i][c] = f[i + 1][c];

            int k = c, score = 0;
            for (int j = 0; j < m; ++j) {
                if (s[k] == vec[i][j]) {
                    if (++k == 5) {
                        score += 5;
                        k = 0;
                    }
                } else if (s.contains(vec[i][j])) {
                    score--;
                }
            }
            f[i][c] = max(f[i][c], f[i + 1][k] + score);
        }
    }
    cout << f[0][0] << "\n";
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