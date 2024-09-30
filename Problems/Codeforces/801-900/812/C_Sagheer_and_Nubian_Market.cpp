#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    auto check = [&](auto k) {
        vector<ll> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = vec[i] + (i + 1) * 1ll * k;
        }

        ranges::sort(res);

        ll sum = accumulate(res.begin(), res.begin() + k, 0ll);
        return pair {sum <= s, sum};
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        auto mid = l + (r - l) / 2;

        if (check(mid).first) {
            l = mid;
        } else {
            r = mid;
        }
    }

    auto [_, sum] = check(l);
    cout << l << " " << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}