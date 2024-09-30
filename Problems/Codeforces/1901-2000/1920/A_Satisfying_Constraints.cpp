#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int k1 = 0, k2 = INT_MAX;
    // unordered_map<int, int> ump;
    vector<int> vec;
    while (n--) {
        int a, x;
        cin >> a >> x;

        if (a == 1) {
            k1 = max(k1, x);
        }
        if (a == 2) {
            k2 = min(k2, x);
        }
        if (a == 3) {
            // ump[x]++;
            vec.emplace_back(x);
        }
    }

    // if (k1 > k2) {
    //     cout << 0 << "\n";
    //     return;
    // }

    int cnt = k2 - k1 + 1;
    // for (auto& v : ump) {
    for (int& v : vec) {
        // cnt -= v.first >= k1 && v.first <= k2;
        cnt -= v >= k1 && v <= k2;

        // if (cnt == 0) {
        //     cout << 0 << "\n";
        //     return;
        // }
    }
    // cout << cnt << "\n";
    cout << max(cnt, 0) << "\n";
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
