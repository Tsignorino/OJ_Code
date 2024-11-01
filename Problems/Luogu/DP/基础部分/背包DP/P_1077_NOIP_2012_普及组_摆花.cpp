#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int& v : A) {
        cin >> v;
    }

    // sum(C_i) == m, C_i <= A_i
    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            // todo: 前缀和优化
            for (int k = 1; k <= min(A[i], j); ++k) {
                f[j] = (f[j] + f[j - k]) % MOD;
            }
        }
    }
    cout << f[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}