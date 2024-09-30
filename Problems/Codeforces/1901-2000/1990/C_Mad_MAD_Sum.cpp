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

    int len = ranges::max(vec);

    auto work = [&]() {
        vector<int> ok(len + 1);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (ok[vec[i]]) {
                mx = max(mx, vec[i]);
            }
            ok[vec[i]] = 1;
            vec[i] = mx;
        }
    };

    // 至多操作两次出现 “右移”
    ll ans = accumulate(vec.begin(), vec.end(), 0ll);
    work();
    ans += accumulate(vec.begin(), vec.end(), 0ll);
    work();

    for (int i = 0; i < n; ++i) {
        ans += (n - i) * 1ll * vec[i];
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