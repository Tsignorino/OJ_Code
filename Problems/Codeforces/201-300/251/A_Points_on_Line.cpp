#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            (vec[i] + d >= vec[mid] ? l : r) = mid;
        }
        ans += (l - i - 1) * 1ll * (l - i) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
