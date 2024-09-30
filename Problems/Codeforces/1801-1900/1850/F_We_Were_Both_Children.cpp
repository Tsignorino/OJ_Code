#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    vector<int> res(n + 1); // 统计倍数的出现次数

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            cnt[val]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int k = i; k <= n; k += i) {
            res[k] += cnt[i];
        }
    }
    cout << *max_element(res.begin(), res.end()) << "\n";
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
