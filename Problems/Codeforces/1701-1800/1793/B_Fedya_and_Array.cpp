#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    vector<int> ans;
    for (int i = a; i > b; --i) {
        ans.push_back(i);
    }
    for (int i = b; i < a; ++i) {
        ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int& v : ans) {
        cout << v << " ";
    }
    cout << "\n";
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