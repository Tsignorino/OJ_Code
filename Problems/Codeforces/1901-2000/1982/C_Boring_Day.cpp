#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    dp
*/

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    // vector<ll> pre(n + 1);
    // for (int i = 0; i < n; ++i) {
    //     pre[i + 1] = pre[i] + vec[i];
    // }

    vector<int> f(n + 1);
    int j = -1, sum = 0;
    for (int i = 0; i < n; ++i) {
        f[i + 1] = max(f[i + 1], f[i]);

        if (j < i) {
            j = i, sum = 0;
        }
        while (j < n && sum < l) {
            sum += vec[j++];
        }

        if (sum >= l && sum <= r) {
            f[j] = max(f[j], f[i] + 1);
        }
        sum -= vec[i];
    }

    cout << f[n] << "\n";
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