#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    int sx, sy;
    cin >> sx >> sy;

    vector<pair<int, int>> vec(n);
    for (auto& [x, y] : vec) {
        cin >> x >> y;
    }

    vector<double> dis(n);
    for (int i = 0; i < n; ++i) {
        dis[i] = hypot(vec[i].first - sx, vec[i].second - sy);
    }

    vector<double> a(n + 1);
    double sum = dis[0] + dis.back();
    for (int i = 1; i < n; ++i) {
        double diff = hypot(vec[i].first - vec[i - 1].first, vec[i].second - vec[i - 1].second);
        sum += diff;
        a[i] = dis[i - 1] + dis[i] - diff;
    }

    vector<double> dp(n + 1);
    deque<int> q;
    q.emplace_back(0);
    for (int i = 1; i <= n; ++i) {
        while (q.front() < i - k) {
            q.pop_front();
        }
        dp[i] = dp[q.front()] + a[i];
        while (!q.empty() && dp[i] < dp[q.back()]) {
            q.pop_back();
        }
        q.emplace_back(i);
    }

    cout << fixed << setprecision(15) << sum + dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}