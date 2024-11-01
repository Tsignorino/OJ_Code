#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);
    ll s = sum / 2;
    ll ans = (sum + 1) / 2;
    for (int i = n - 1; i >= 0; --i) {
        if (s > 0) {
            s -= vec[i];
            ans++;
        }
    }
    cout << ans << "\n";
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