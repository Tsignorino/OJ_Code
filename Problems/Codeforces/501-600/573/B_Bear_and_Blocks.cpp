#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> res(vec);
    res.insert(res.begin(), 0);
    res.insert(res.end(), 0);
    for (int i = 1; i <= n; ++i) {
        res[i] = min(res[i], res[i - 1] + 1);
    }

    int ans = 0;
    for (int i = n; i > 0; --i) {
        res[i] = min(res[i], res[i + 1] + 1);
        ans = max(ans, res[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
