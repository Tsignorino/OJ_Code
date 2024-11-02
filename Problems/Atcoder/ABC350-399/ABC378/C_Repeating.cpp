#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;

        if (mp.contains(v)) {
            cout << mp[v] << " ";
        } else {
            cout << -1 << " ";
        }
        mp[v] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}