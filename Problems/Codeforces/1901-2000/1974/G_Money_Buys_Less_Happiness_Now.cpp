#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    priority_queue<int> q;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        sum -= v;
        q.emplace(v);
        if (sum < 0) {
            sum += q.top();
            q.pop();
        }

        sum += x;
    }
    cout << q.size() << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
