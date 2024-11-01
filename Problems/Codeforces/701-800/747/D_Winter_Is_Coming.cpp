#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> gap;
    int ans = 0;
    int cnt = INT_MIN;
    bool pre = true;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        bool flag = val >= 0; // false: winter
        if (flag != pre) {
            ans++;
            if (flag) {
                cnt = 0;
            } else if (cnt > 0) {
                gap.emplace_back(cnt);
            }
        }

        if (flag) {
            cnt++;
        } else if (--k < 0) {
            cout << -1 << "\n";
            return;
        }

        pre = flag;
    }

    ranges::sort(gap);

    for (int& v : gap) {
        if (k < v) {
            break;
        }
        k -= v;
        ans -= 2;
    }

    ans -= cnt > 0 && cnt <= k; // keep winter tires
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
