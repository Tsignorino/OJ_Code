#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        mx = max(mx, b[i]);
        b[i] -= k;
    }

    const int N = mx * n;
    vector<int> f(N * 2 + 3, INT_MIN);
    f[N] = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > 0) {
            for (int j = N * 2; j >= 0; --j) {
                if (j + b[i] <= N * 2 && j + b[i] >= 0) {
                    f[j + b[i]] = max(f[j + b[i]], f[j] + a[i]);
                }
            }
        } else {
            for (int j = 0; j <= N * 2; ++j) {
                if (j + b[i] <= N * 2 && j + b[i] >= 0) {
                    f[j + b[i]] = max(f[j + b[i]], f[j] + a[i]);
                }
            }
        }
    }
    cout << *max_element(f.begin(), f.begin() + N + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}