#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);
    if (sum <= k) {
        cout << n << "\n";
        return;
    }

    int l = 0;
    for (ll left = (k + 1) / 2; left >= vec[l]; ++l) {
        left -= vec[l];
    }

    int r = n - 1;
    for (ll right = k / 2; right >= vec[r]; --r) {
        right -= vec[r];
    }
    cout << l + n - 1 - r << "\n";
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