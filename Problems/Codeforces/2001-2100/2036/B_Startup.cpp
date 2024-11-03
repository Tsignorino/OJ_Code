#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(k);
    for (int i = 0; i < k; ++i) {
        int b, c;
        cin >> b >> c;
        b--;
        vec[b] += c;
    }

    ranges::sort(vec, greater<>());

    cout << accumulate(vec.begin(), min(vec.begin() + n, vec.end()), 0ll) << "\n";
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