#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // 对取得的 ai 的最小值在 (0, max(a)] 二分
    auto check = [&](int m) {
        ll sum = 0, tot = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= m) {
                ll cnt = (a[i] - m) / b[i] + 1;
                tot += cnt;
                sum += a[i] * cnt - cnt * (cnt - 1) / 2 * b[i];
            }
        }
        return pair(tot, sum);
    };

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        (check(m).first <= k ? r : l) = m;
    }

    auto [tot, sum] = check(r);
    sum += (k - tot) * l;
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