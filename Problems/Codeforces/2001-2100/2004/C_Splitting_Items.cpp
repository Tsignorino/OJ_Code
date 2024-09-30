#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    priority_queue<int> pq {vec.begin(), vec.end()};

    ll ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int d = min(k, a - b);
        k -= d;
        ans += a - b - d;
    }

    if (!pq.empty()) {
        ans += pq.top();
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