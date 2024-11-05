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

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> f(n + 1, n); // 使后缀合法的操作次数
    f[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        f[i] = f[i + 1] + 1;
        if (int j = i + vec[i] + 1; j <= n) {
            f[i] = min(f[i], f[j]);
        }
    }
    cout << f[0] << "\n";
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