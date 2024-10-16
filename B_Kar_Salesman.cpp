#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    auto check = [&](auto x) {
        
        return true;
    };

    ll l = 0, r = 1e15;
    while (l + 1 < r) {
        auto mid = l + (r - l) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}