#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        g[A][B] = C;
        g[B][A] = -C;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][k] && g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    vector<int> beg(N, 1);
    for (int i = 0; i < N; i++) {
        if (!beg[i]) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            if (g[i][j]) {
                beg[j] = 0;
            }
        }
    }

    vector<int> minV(N), maxV(N), mask(N);
    for (int x = 0; x < N; x++) {
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                minV[x] = min(minV[x], g[i][x]);
                maxV[x] = max(maxV[x], g[i][x]);
            }
        }
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                mask[x] |= 1 << (g[i][x] - minV[x]);
            }
        }
    }

    for (int x = 0; x < N; x++) {
        vector<int> vis(N);
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                vis[i] = 1;
            }
        }
        
        vector<int> dp(1 << N), f(1 << N, -1);
        f[(1 << N) - 1] = 0;
        int ans = -1;
        int cnt = 0;
        for (int s = (1 << N) - 1; s > 0; s--) {
            if (f[s] == -1) {
                continue;
            }
            int i = f[s];
            while (i < N && (vis[i] || !beg[i])) {
                i++;
            }
            if (i == N) {
                i = x;
                assert(__builtin_popcount(mask[x]) == __builtin_popcount(s));
            }
            for (int j = 0; j + maxV[i] - minV[i] < N; j++) {
                int m = mask[i] << j;
                if ((s & m) == m) {
                    f[s ^ m] = i + 1;
                    if (i == x) {
                        ans = j - minV[x] + 1;
                        cnt++;
                    }
                }
            }
        }
        if (cnt > 1) {
            ans = -1;
        }
        cout << ans << " \n"[x == N - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
