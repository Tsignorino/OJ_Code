#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

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

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> vec(m);
    vector<char> str(m, ' ');
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        while (c--) {
            int v;
            cin >> v;
            vec[i].emplace_back(v);
        }
        cin >> str[i];
    }

    int k = 0;
    int ans = 0;
    do {
        bool flag = true;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int& v : vec[i]) {
                cnt += (k >> (v - 1)) & 1;
            }

            if (cnt >= x && str[i] == 'x' || cnt < x && str[i] == 'o') {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    } while (k++ < (2 << (n - 1)) - 1);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve_();

    return 0;
}
