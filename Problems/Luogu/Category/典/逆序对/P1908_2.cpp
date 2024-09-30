#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    树状数组求逆序对
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> tmp(vec);
    ranges::sort(tmp);
    for (int& v : vec) {
        v = ranges::lower_bound(tmp, v) - tmp.begin();
    }

    vector<int> tree(n + 1);
    ll ans = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = vec[k] + 1; i <= n; i += i & -i) {
            tree[i] += 1;
        }

        ll sum = 0;
        for (int i = vec[k] + 1; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        ans += k + 1 - sum;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
