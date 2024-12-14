// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int g = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        g = gcd(g, abs(v));
    }
    cout << g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}