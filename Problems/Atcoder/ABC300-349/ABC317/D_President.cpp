#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    int m = accumulate(z.begin(), z.end(), 0);

    vector<ll> f(m + 1, LLONG_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = max((x[i] + y[i] + 1) / 2 - x[i], 0);
        for (int j = m; j >= z[i]; --j) {
            f[j] = min(f[j], f[j - z[i]] + v);
        }
    }
    cout << *min_element(f.begin() + (m + 1) / 2, f.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}