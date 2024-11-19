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

    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int& v : a) {
        cin >> v;
        cnt[v]++;
    }

    n -= 2;
    for (int i = 1; i <= n; ++i) {
        if (n % i) {
            continue;
        }
        int j = n / i;
        if (i == j ? cnt[i] >= 2 : cnt[i] && cnt[j]) {
            cout << i << " " << j << "\n";
            return;
        }
    }
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