#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88392/D
*/

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll sum = -1;
    for (int i = 0; i < n - 2; ++i) {
        if (vec[i] + vec[i + 1] > vec[i + 2]) {
            sum = max(sum, vec[i] + vec[i + 1] + vec[i + 2]);
        }
    }
    // for (int i = 0; i < n - 2; ++i) {
    //     for (int j = n - 2; j > i; --j) {
    //         ll res = vec[i] + vec[j];
    //         auto iter = lower_bound(vec.begin() + j + 1, vec.end(), res);
    //         if (prev(iter) != vec.begin() + j && *prev(iter) > vec[j] - vec[i]) {
    //             sum = max(sum, res + *prev(iter));
    //             break;
    //         }
    //     }
    // }
    cout << sum << "\n";
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