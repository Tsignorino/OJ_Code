#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), w(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : w) {
        cin >> v;
    }

    ll ans = 0;
    map<int, int> map;
    for (int i = 0; i < n; ++i) {
        if (map[a[i]] == 0) {
            map[a[i]] = w[i];
        } else {
            ans += min(map[a[i]], w[i]);
            if (map[a[i]] < w[i]) {
                map[a[i]] = w[i];
            }
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
