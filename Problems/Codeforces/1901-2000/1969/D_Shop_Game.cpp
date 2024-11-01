#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://www.bilibili.com/video/BV1qM4m1f7jq

    a[i]    Alice 要不要买
    b[i]    Bob 要不要白嫖（取决于 b[i]）

    k = 1
    1> 100  13  2
       200  10  5
    2> 1    5   1000
       5000 10  2000
*/

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

    ranges::sort(vec, [&](const auto& p1, const auto& p2) { return p1.second > p2.second; });

    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + max(vec[i].second - vec[i].first, 0);
    }

    if (k == 0) {
        cout << suf[0] << "\n";
        return;
    }

    priority_queue<int> q;
    ll cur = 0;
    for (int i = 0; i < k; ++i) {
        q.emplace(vec[i].first);
        cur += vec[i].first;
    }

    ll ans = 0;
    for (int i = k; i < n; ++i) {
        ans = max(ans, suf[i] - cur);
        if (vec[i].first < q.top()) {
            cur -= q.top();
            q.pop();
            cur += vec[i].first;
            q.emplace(vec[i].first);
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