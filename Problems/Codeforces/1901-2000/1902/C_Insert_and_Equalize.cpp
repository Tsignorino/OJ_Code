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

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    ranges::sort(vec);

    int d = 0;
    for (int i = 1; i < n; ++i) {
        d = gcd(d, vec[i] - vec[i - 1]);
    }

    set<int> s(vec.begin(), vec.end());

    ll ans = 0;
    int mx = *s.rbegin(), v = mx;
    for (int i = 0;; ++i) {
        if (s.contains(v)) {
            v -= d;
        } else {
            ans = i;
            break;
        }
    }

    for (int& v : vec) {
        ans += (mx - v) / d;
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