#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n;
    cin >> n;

    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }

    vector<array<int, 2>> f(n);
    f[0][0] = R[0] - 1 + (R[0] - L[0]);
    f[0][1] = R[0] - 1;
    for (int i = 1; i < n; ++i) {
        f[i][0] = min(f[i - 1][0] + abs(R[i] - L[i - 1]), f[i - 1][1] + abs(R[i - 1] - R[i])) + R[i] - L[i];
        f[i][1] = min(f[i - 1][0] + abs(L[i - 1] - L[i]), f[i - 1][1] + abs(R[i - 1] - L[i])) + R[i] - L[i];
    }
    cout << min(f[n - 1][0] + n - L[n - 1], f[n - 1][1] + n - R[n - 1]) + (n - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}