#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    sort(a.begin(), a.end());

    int id = (n - 1) / 2, val = a[id];
    int cnt = 0;
    for (int i = id; i < n; ++i) {
        cnt += a[i] == val;
    }

    cout << cnt << "\n";
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
