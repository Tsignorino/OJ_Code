#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    multiset<int> set(vec.begin(), vec.end());

    ll ans = 0;
    while (m--) {
        int v;
        cin >> v;

        auto iter = set.lower_bound(v);
        if (iter == set.end()) {
            cout << -1 << "\n";
            return;
        }
        ans += *iter;
        set.extract(*iter);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}