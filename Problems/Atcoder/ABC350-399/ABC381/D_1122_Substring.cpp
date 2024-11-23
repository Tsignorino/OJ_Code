// Date: 2024-11-23  星期六

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

    auto f = [&](vector<int>& vec) {
        int k = vec.size();
        int res = 0;
        set<int> vis;
        for (int l = 0, r = 0; l < k; ++l) {
            while (r < k && !vis.contains(vec[r])) {
                vis.emplace(vec[r++]);
            }
            vis.extract(vec[l]);
            res = max(res, r - l);
        }
        return res;
    };

    int ans = 0;
    vector<int> vec;
    for (int i : {0, 1}) {
        for (; i < n - 1; i += 2) {
            if (a[i] == a[i + 1]) {
                vec.push_back(a[i]);
            } else {
                ans = max(ans, f(vec));
                vec.clear();
            }
        }
        ans = max(ans, f(vec));
    }
    cout << ans * 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}