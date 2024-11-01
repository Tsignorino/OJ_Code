#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int q;
    cin >> q;

    int c1 = 0, c2 = 0;
    while (q--) {
        int v1, v2;
        cin >> v1 >> v2;

        c1 += v1, c2 += v2;
    }

    if (c1 > c2) {
        cout << "Takahashi\n";
    } else if (c1 < c2) {
        cout << "Aoki\n";
    } else {
        cout << "Draw\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}