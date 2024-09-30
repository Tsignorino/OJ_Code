#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt = max(cnt, ++mp[val]);
    }
    cout << n - cnt << "\n";
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