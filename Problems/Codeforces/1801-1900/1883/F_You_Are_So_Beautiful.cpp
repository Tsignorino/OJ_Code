#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    map<int, int> first, last;
    for (int i = 0; i < n; ++i) {
        if (!first.contains(vec[i])) {
            first[vec[i]] = i;
        }
        last[vec[i]] = i;
    }

    vector<int> left(n), right(n);
    for (auto& [v, id] : first) {
        left[id] = 1;
    }
    for (auto& [v, id] : last) {
        right[id] = 1;
    }

    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += left[i];
        ans += cnt * right[i];
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