#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

static constexpr int N = 1e8;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll ans = accumulate(vec.begin(), vec.end(), 0ll) * (n - 1);
    for (int i = 0; i < n; ++i) {
        ans -= (vec.end() - ranges::lower_bound(vec.begin() + i + 1, vec.end(), N - vec[i])) * 1ll * N;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
