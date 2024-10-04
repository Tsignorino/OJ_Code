#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> vec(n + 1);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> f(n + 1, INT_MIN);
    f[0] = 0;

    deque<int> q;
    int ans = INT_MIN;
    for (int i = l; i <= n; ++i) {
        while (!q.empty() && f[i - l] > f[q.back()]) {
            q.pop_back();
        }
        q.emplace_back(i - l);

        while (!q.empty() && q.front() + r < i) {
            q.pop_front();
        }

        int id = q.front();
        f[i] = f[id] + vec[i];
        if (i + r > n) {
            ans = max(ans, f[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}