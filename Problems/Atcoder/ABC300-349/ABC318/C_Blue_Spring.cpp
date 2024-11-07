#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, d, p;
    cin >> n >> d >> p;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    priority_queue<int> q(vec.begin(), vec.end());
    ll ans = 0;
    while (!q.empty()) {
        ll cost = 0;
        for (int i = 0; i < d && !q.empty(); ++i) {
            cost += q.top();
            q.pop();
        }
        ans += min(cost, p * 1ll);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}