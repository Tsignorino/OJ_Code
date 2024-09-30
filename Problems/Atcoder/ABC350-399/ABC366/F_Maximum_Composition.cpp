#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);
    for (auto& [a, b] : vec) {
        cin >> a >> b;
    }

    ranges::sort(vec, [&](const auto& p, const auto& q) {
        auto [a1, b1] = p;
        auto [a2, b2] = q;
        return a1 * b2 + b1 < a2 * b1 + b2;
    });

    vector<ll> f(k + 1, 1);
    for (auto& [a, b] : vec) {
        for (int i = k; i > 0; --i) {
            f[i] = max(f[i], f[i - 1] * a + b);
        }
    }
    cout << f[k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}