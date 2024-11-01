#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    ll lcm_ = 1;
    for (int& v : vec) {
        cin >> v;
        lcm_ = lcm(lcm_, v);
    }

    ll res = 0;
    for (int& v : vec) {
        res += lcm_ / v;
    }
    if (res >= lcm_) {
        cout << -1 << "\n";
        return;
    }

    for (int& v : vec) {
        cout << lcm_ / v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
