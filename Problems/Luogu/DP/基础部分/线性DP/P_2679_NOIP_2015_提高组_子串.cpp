#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    string s, t;
    cin >> s >> t;

    vector f(2, vector(M + 1, vector(K + 1, vector<int>(2))));
    f[0][0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        f[(i + 1) % 2][0][0][0] = 1;
        for (int j = 0; j < min(i + 1, M); ++j) {
            for (int k = 0; k < min(j + 1, K); ++k) {
                f[(i + 1) % 2][j + 1][k + 1][0] = f[(i + 1) % 2][j + 1][k + 1][1] = 0;

                f[(i + 1) % 2][j + 1][k + 1][0] = (f[i % 2][j + 1][k + 1][0] + f[i % 2][j + 1][k + 1][1]) % MOD;
                if (s[i] == t[j]) {
                    f[(i + 1) % 2][j + 1][k + 1][1] = ((f[i % 2][j][k + 1][1] + f[i % 2][j][k][0]) % MOD + f[i % 2][j][k][1]) % MOD;
                }
            }
        }
    }
    cout << (f[N & 1][M][K][0] + f[N & 1][M][K][1]) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}