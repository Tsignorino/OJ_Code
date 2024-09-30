#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        // [l, r] 奇数个数 / 2
        cout << ((r + 1) / 2 - l / 2) / 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}