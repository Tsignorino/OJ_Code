#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll now = 0;
    for (int i = 0; i < n; ++i) {
        int Op;
        cin >> Op;

        if (Op == 1) {
            q.emplace(now);
        } else if (Op == 2) {
            ll t;
            cin >> t;
            now += t;
        } else {
            ll h;
            cin >> h;

            int ans = 0;
            while (!q.empty()) {
                if (q.top() > now - h) {
                    break;
                }
                q.pop();
                ans++;
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}