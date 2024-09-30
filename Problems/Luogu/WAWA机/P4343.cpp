#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    auto f = [&](ll mid) {
        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            sum += vec[i];
            sum = max(sum, 0ll);
            if (sum >= mid) {
                sum = 0;
                cnt++;
            }
        }
        return cnt;
    };

    ll low = -1, high = -1;

    ll l = 0, r = LLONG_MAX / 2;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if (f(mid) > k) {
            l = mid;
        } else {
            r = mid;
            low = mid;
        }
    }

    l = 0, r = LLONG_MAX / 2;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if (f(mid) < k) {
            r = mid;
        } else {
            l = mid;
            high = mid;
        }
    }

    if (low == -1 || high == -1 || high < low) {
        cout << -1 << "\n";
    } else {
        cout << low << " " << high << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
