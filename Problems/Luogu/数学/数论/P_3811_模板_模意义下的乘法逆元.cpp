// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

vector<int> Inv(int n, int p) {
    vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = p - inv[p % i] * 1ll * (p / i) % p;
    }
    return inv;
}

void solve() {
    int n, p;
    cin >> n >> p;

    auto inv = Inv(n, p);
    for (int i = 1; i <= n; ++i) {
        cout << inv[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}