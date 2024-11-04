#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    auto f = [&](const vector<int>& b) {
        int cnt = 0;
        for (int i = 1; i < n - 1; ++i) {
            cnt += a[i] + b[i] > a[i - 1] + b[i - 1] && a[i] + b[i] > a[i + 1] + b[i + 1];
        }
        return cnt;
    };

    vector<int> ans;
    int cnt = 0;
    for (int j : {0, 1}) {
        vector<int> r(n);
        iota(r.begin(), r.end(), 0);

        ranges::sort(r, {}, [&](int i) { return pair(i != 0 && i != n - 1 && i % 2 == j, -a[i]); });

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[r[i]] = i + 1;
        }

        int v = f(res);
        if (v >= cnt) {
            cnt = v;
            ans = std::move(res);
        }
    }

    for (int& v : ans) {
        cout << v << " ";
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