#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    array<int, 3> arr;
    for (int& v : arr) {
        cin >> v;
    }

    ranges::sort(arr);

    cout << max(abs(arr[0] - arr[2]) + abs(arr[1] - arr[2]) + abs(arr[0] - arr[1]) - 4, 0) << "\n";
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