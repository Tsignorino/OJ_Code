#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> f(n); // 从 0 号到 i 号的距离
    f[1] = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (vec[i + 1] - vec[i] > vec[i] - vec[i - 1]) {
            f[i + 1] = vec[i + 1] - vec[i];
        } else {
            f[i + 1] = 1;
        }
        f[i + 1] += f[i];
    }

    vector<ll> g(n); // 从 n-1 号到 i 号的距离
    g[n - 2] = 1;
    for (int i = n - 2; i > 0; --i) {
        if (vec[i + 1] - vec[i] > vec[i] - vec[i - 1]) {
            g[i - 1] = 1;
        } else {
            g[i - 1] = vec[i] - vec[i - 1];
        }
        g[i - 1] += g[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l < r) {
            cout << f[r] - f[l] << "\n";
        } else {
            cout << g[r] - g[l] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}