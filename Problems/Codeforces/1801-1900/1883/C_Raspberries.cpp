#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k; // n >= 2, k ∈ [2, 5]

    vector<int> vec(n);
    int ans = 11, cnt = 0;
    for (int& v : vec) {
        cin >> v;

        ans = min(ans, v % k == 0 ? 0 : k - v % k);

        cnt += v % 2 == 0; // if k == 4, then needs 2 even numbers
    }
    cout << (k == 4 ? min(ans, max(2 - cnt, 0)) : ans) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
