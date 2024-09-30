#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    ll C;
    cin >> a >> b >> C;

    int c = __popcount(C);
    if ((a - b + c) % 2) {
        cout << -1 << "\n";
        return;
    }

    int x = (a - b + c) / 2;
    int y = a - x;
    if (x < 0 || x > c || y < 0 || c + y > 60) {
        cout << -1 << "\n";
        return;
    }

    ll A = 0, B = 0;
    for (int i = 0; i < 60; ++i) {
        if (C >> i & 1) {
            (x-- > 0 ? A : B) |= 1ll << i;
        } else if (y-- > 0) {
            A |= 1ll << i;
            B |= 1ll << i;
        }
    }
    cout << A << " " << B << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}