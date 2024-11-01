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

    string s;
    cin >> s;

    ll ans = 0;
    deque<int> q;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            q.push_back(i + 1);
        } else {
            if (!q.empty()) {
                q.pop_front();
            }
            ans += i + 1;
        }
    }
    while (q.size() > 1) {
        q.pop_front();
        ans += q.back();
        q.pop_back();
    }
    if (!q.empty()) {
        ans += q.back();
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