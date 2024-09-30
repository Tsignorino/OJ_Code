#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);
    for (auto& [a, b] : vec) {
        cin >> a >> b;
    }

    ranges::sort(vec);

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i].second;
    }

    auto check = [&](int x) {
        int id = lower_bound(vec.begin(), vec.end(), x, [&](pair<int, int>& p, int x) { return p.first < x; }) - vec.begin();
        return pre[n] - pre[id] <= k;
    };

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}