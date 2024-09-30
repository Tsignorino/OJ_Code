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

    int l = vec[0], r = vec[0];
    for (int i = 1; i < n; ++i) {
        if (vec[i] == l - 1) {
            l--;
        } else if (vec[i] == r + 1) {
            r++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    // set<int> s {vec[0]};
    // for (int i = 1; i < n; ++i) {
    //     if (!s.contains(vec[i] - 1) && !s.contains(vec[i] + 1)) {
    //         cout << "NO\n";
    //         return;
    //     }
    //     s.emplace(vec[i]);
    // }
    // cout << "YES\n";
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