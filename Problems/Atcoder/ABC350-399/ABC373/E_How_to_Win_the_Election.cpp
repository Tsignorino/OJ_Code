#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    k -= accumulate(vec.begin(), vec.end(), 0ll);

    vector<ll> res(vec);
    ranges::sort(res, greater<>());
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + res[i];
    }

    // 从小到大排序，方便后续 "个数" 的计算
    vector<ll> res2(vec);
    ranges::sort(res2);

    auto check = [&](auto x, int i, int cnt) {
        // 原来就比 vec[i] + x 大的
        int C = n - (ranges::upper_bound(res2, vec[i] + x) - res2.begin());
        if (C >= m) {
            return false;
        }

        ll s = (cnt < m ? pre[m + 1] - vec[i] : pre[m]) - pre[C];
        return (vec[i] + x + 1) * (m - C) - s > k - x;
    };

    for (int i = 0; i < n; ++i) {
        // 大于等于 vec[i] 的（不包含自己）
        int cnt = n - 1 - (ranges::lower_bound(res2, vec[i]) - res2.begin());

        ll l = -1, r = k + 1;
        while (l + 1 < r) {
            auto mid = l + (r - l) / 2;

            if (check(mid, i, cnt)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << (r == k + 1 ? -1 : r) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}