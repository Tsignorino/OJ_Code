#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    // sum(a) / sum(b) = k -> sum(a - k * b) = 0
    // sum(a) 的最大值 ?
    // V[i] = a[i] - k * b[i]   value = a[i]
    const int V = 100 * n;
    vector<int> f(V + 1, INT_MIN / 2), g(V + 1, INT_MIN / 2);
    f[0] = g[0] = 0;
    for (int i = 0; i < n; ++i) {
        int c = a[i] - k * b[i];
        if (c >= 0) {
            for (int j = V; j >= c; --j) {
                f[j] = max(f[j], f[j - c] + a[i]);
            }
        } else {
            for (int j = V; j >= -c; --j) {
                g[j] = max(g[j], g[j + c] + a[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= V; ++i) {
        ans = max(ans, f[i] + g[i]);
    }
    cout << (ans == 0 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
