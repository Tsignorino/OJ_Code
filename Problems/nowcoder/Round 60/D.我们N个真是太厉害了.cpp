#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    同：https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/  T-1798
*/

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll sum = 0;
    for (int& v : vec) {
        if (sum >= v - 1) {
            sum += v;
        } else {
            break;
        }
    }

    if (sum >= n) {
        cout << "Cool!\n";
    } else {
        cout << sum + 1 << "\n";
    }
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