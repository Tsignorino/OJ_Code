#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);
    if (sum <= m) {
        cout << "infinite\n";
        return;
    }

    ranges::sort(vec);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        int id = ranges::upper_bound(vec, mid) - vec.begin();
        if (pre[id] + mid * 1ll * (n - id) <= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}