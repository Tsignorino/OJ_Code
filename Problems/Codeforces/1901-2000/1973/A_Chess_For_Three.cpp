#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) & 1) {
        cout << -1 << "\n";
        return;
    }
    // promise: a <= b <= c
    cout << min(a + b, (a + b + c) / 2) << "\n";
}

void mysolve() {
    vector<int> vec(3);
    for (int& v : vec) {
        cin >> v;
    }

    if (accumulate(vec.begin(), vec.end(), 0) & 1) {
        cout << -1 << "\n";
        return;
    }

    multiset<int> set(vec.begin(), vec.end());
    int ans = 0;
    while (set.size() > 1) {
        int v1 = *set.begin();
        int v2 = *set.rbegin();
        set.erase(set.begin());
        set.erase(prev(set.end()));
        if (v1 && v2) {
            v1--, v2--, ans++;
        }
        if (v1 > 0) {
            set.insert(v1);
        }
        if (v2 > 0) {
            set.insert(v2);
        }
    }
    cout << ans << "\n";
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
