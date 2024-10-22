#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 前置：https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/  任意子数组和的绝对值的最大值

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    if (vec[0] == vec[n - 1]) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    ll s = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        if (s >= 0) {
            cout << vec[l] << " ";
            s += vec[l++];
        } else {
            cout << vec[r] << " ";
            s += vec[r--];
        }
    }
    cout << "\n";
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