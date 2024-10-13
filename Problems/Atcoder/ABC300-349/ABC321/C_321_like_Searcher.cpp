#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int k;
    cin >> k;

    // 9 8 7 6 5 4 3 2 1 0
    vector<ll> vec;
    for (int i = 1; i < (1 << 10); ++i) {
        ll x = 0;
        for (int j = 9; j >= 0; --j) {
            if (i >> j & 1) {
                x = x * 10 + j;
            }
        }
        vec.emplace_back(x);
    }

    ranges::sort(vec);

    cout << vec[k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}