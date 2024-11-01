#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    vector<int> rowSum(n), colSum(n);
    for (int i = 0; i < n; ++i) {
        int rs = 0;
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            rs += a[i][j];
        }
        rowSum[i] = rs;
    }
    for (int j = 0; j < n; ++j) {
        int cs = 0;
        for (int i = 0; i < n; ++i) {
            cs += a[i][j];
        }
        colSum[j] = cs;
    }

    ranges::sort(colSum);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += colSum.end() - ranges::upper_bound(colSum, rowSum[i]);
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
