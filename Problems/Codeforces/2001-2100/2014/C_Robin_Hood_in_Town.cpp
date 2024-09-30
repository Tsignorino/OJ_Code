#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    if (n <= 2) {
        cout << -1 << "\n";
        return;
    }

    ranges::sort(vec);

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);
    cout << max(vec[n / 2] * 2ll * n - sum + 1, 0ll) << "\n";
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