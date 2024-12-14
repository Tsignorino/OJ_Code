#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Item {
    int a, b, k;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Item> vec(n);
    for (auto& [a, b, k] : vec) {
        cin >> a >> b >> k;
    }

    vector<ll> f(m + 1);
    for (auto& [a, b, k] : vec) {
        for (int j = m; j >= k; --j) {
            f[j] = max(f[j] + a, f[j - k] + b);
        }
        for (int j = k - 1; j >= 0; --j) {
            f[j] += a;
        }
    }
    cout << f[m] * 5 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}