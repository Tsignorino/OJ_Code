#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int num;
    cin >> num;

    int sum = 0; // sum 统计花出去的量
    while (num) {
        if (num <= 9) {
            sum += num;
            num = 0;
        } else {
            sum += num - num % 10;
            num = num % 10 + num / 10;
        }
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}