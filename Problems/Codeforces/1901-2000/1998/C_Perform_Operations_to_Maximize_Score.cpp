#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].second;
    }

    ranges::sort(vec);

    int l = 0, r = vec[n - 1].first + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        int cnt = 0;
        ll sum = 0;
        for (int i = n - 2; i >= 0 && cnt < (n + 1) / 2; --i) { // !
            if (vec[i].first >= mid) {
                cnt++;
            } else if (vec[i].second == 1) {
                sum += mid - vec[i].first;
                cnt++;
            }
        }
        if (cnt < (n + 1) / 2 || sum > k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    ll ans = l + vec[n - 1].first;
    for (int i = n - 1; i >= 0; --i) {
        if (vec[i].second == 1) {
            vector<int> res;
            ranges::transform(vec, back_inserter(res), [&](const auto& p) { return p.first; });
            res.erase(res.begin() + i);
            ans = max(ans, vec[i].first * 1ll + k + res[n / 2 - 1]);
            break;
        }
    }
    cout << ans << "\n";
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