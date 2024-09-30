#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, int>> vec(n);

    int sum = 0;
    for (auto& v : vec) {
        cin >> v.first >> v.second;
        sum += v.second;
    }

    ranges::sort(vec);
    cout << vec[sum % n].first << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
