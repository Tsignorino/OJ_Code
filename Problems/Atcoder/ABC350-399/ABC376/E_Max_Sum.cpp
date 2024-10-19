#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> b(n);
    for (int& v : b) {
        cin >> v;
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) { return a[i] < a[j]; });

    ll ans = numeric_limits<ll>::max();

    priority_queue<int> q;
    ll sum = 0;
    for (int& i : id) {
        q.emplace(b[i]);
        sum += b[i];
        while (q.size() > k) {
            sum -= q.top();
            q.pop();
        }
        if (q.size() == k) {
            ans = min(ans, sum * a[i]);
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