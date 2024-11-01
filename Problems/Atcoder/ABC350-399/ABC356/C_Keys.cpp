#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve_() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> S(M), R(M);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;

        while (c--) {
            int X;
            cin >> X;
            X--;
            S[i] |= 1 << X;
        }

        char r;
        cin >> r;
        R[i] = (r == 'o');
    }

    int ans = 0;
    for (int s = 0; s < (1 << N); s++) {
        int ok = 1;
        for (int i = 0; i < M; i++) {
            if ((__builtin_popcount(S[i] & s) >= K) != R[i]) {
                ok = 0;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve_();

    return 0;
}
