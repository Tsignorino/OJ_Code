// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int q;
    cin >> q;

    int cnt = 0;
    while (q--) {
        char Op;
        int x;
        cin >> Op >> x;

        if (Op == 'P') {
            cnt += x;
        } else {
            if (x > cnt) {
                cout << "YES\n";
                cnt = 0;
            } else {
                cout << "NO\n";
                cnt -= x;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}