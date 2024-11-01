#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    auto check = [&](int k) {
        int s = 0, e = 0;
        for (int i = 0; i < n; ++i) {
            s = max(s - k, a[i]), e = min(e + k, b[i]);
            if (s > e) {
                return false;
            }
        }
        return true;
    };

    int l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        (check(mid) ? r : l) = mid;
    }
    cout << r << "\n";
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