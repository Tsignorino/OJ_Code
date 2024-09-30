#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    vec.emplace_back(0);

    sort(vec.begin(), vec.end());
    int id = lower_bound(vec.begin(), vec.end(), 0) - vec.begin();

    ll lCost = 0, rCost = 0;
    for (int i = 0; i < id; i += k) {
        lCost += vec[i] * 2;
    }
    for (int i = n; i > id; i -= k) {
        rCost += vec[i] * 2;
    }

    cout << rCost - lCost - max(-vec[0], vec[n]) << "\n";
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
