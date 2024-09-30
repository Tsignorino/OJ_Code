#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    vector<int> cnt(k);
    for (int& val : vec) {
        cin >> val;
        cnt[val % k]++;
    }

    int ans = cnt[0] / 2; // itself
    if (k % 2 == 0) {
        ans += cnt[k / 2] / 2;
    }
    for (int i = 1; i < (k + 1) / 2; ++i) {
        ans += min(cnt[i], cnt[k - i]);
    }

    cout << ans * 2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
