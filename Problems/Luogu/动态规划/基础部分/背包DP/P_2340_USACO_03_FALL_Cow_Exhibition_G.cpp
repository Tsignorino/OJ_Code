#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        m = max({m, abs(a[i]), abs(b[i])});
    }

    /*
        选或不选 ==> 0-1 背包（体积--牛的智商，价值--牛的情商）
    */
    const int N = n * m;
    vector<int> f(N * 2 + m + 1, numeric_limits<int>::min() / 2);
    f[N] = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            for (int j = N * 2; j >= a[i]; --j) {
                f[j] = max(f[j], f[j - a[i]] + b[i]);
            }
        } else {
            for (int j = 0; j <= N * 2 + a[i]; ++j) {
                f[j] = max(f[j], f[j - a[i]] + b[i]);
            }
        }
    }

    int ans = 0;
    for (int i = N; i <= N * 2; ++i) {
        if (f[i] >= 0) {
            ans = max(ans, i + f[i] - N);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
