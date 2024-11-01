#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    d++;

    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
        vector<int> a(m);
        for (int& v : a) {
            cin >> v;
            v++; // cost
        }

        vector<ll> dp(m, LLONG_MAX / 2);
        dp[0] = 1;
        deque<int> q;
        for (int j = 1; j < m; ++j) {
            while (!q.empty() && dp[j - 1] < dp[q.back()]) {
                q.pop_back();
            }
            q.push_back(j - 1);

            while (q.front() < j - d) {
                q.pop_front();
            }
            dp[j] = a[j] + dp[q.front()];
        }
        cost[i] = dp[m - 1];
    }

    /* Brute Force
    ll ans = LLONG_MAX / 2;
    for (int i = 0; i + k <= n; ++i) {
        ll sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += cost[i + j];
        }
        ans = min(ans, sum);
    }
    */
    
    ll sum = accumulate(cost.begin(), cost.begin() + k, 0LL);
    ll ans = sum;
    for (int j = k; j < n; ++j) {
        sum = sum - cost[j - k] + cost[j];
        ans = min(ans, sum);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
