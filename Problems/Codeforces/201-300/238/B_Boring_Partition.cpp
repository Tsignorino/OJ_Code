#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, h;
    cin >> n >> h;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int id = find(vec.begin(), vec.end(), ranges::min(vec)) - vec.begin();

    ranges::sort(vec);

    int mn1 = vec[0], mn2 = vec[1], mn3 = n >= 3 ? vec[2] : 1e9;
    int mx1 = vec[n - 1], mx2 = vec[n - 2];

    int f1 = (mx1 + mx2) - (mn1 + mn2);
    int f2 = max(mx1 + mx2, mn1 + mx1 + h) - min(mn2 + mn3, mn1 + mn2 + h);
    cout << min(f1, f2) << "\n";

    vector<int> ans(n, 1);
    if (f2 < f1) {
        ans[id] = 2;
    }
    for (int& v : ans) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}