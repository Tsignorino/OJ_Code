#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

int next(int x) {
    return x + x % 10;
}

void solve() {
    int n;
    cin >> n;
    bool flag = false;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
        if (v % 5 == 0) {
            flag = true;
            v = next(v);
        }
    }

    if (flag) {
        cout << (ranges::max(vec) == ranges::min(vec) ? "YES" : "NO") << "\n";
        return;
    }

    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; ++i) {
        while (vec[i] % 10 != 2) {
            vec[i] = next(vec[i]);
        }
        (vec[i] % 20 == 2 ? flag1 : flag2) = true;
    }
    cout << ((flag1 & flag2) ? "NO" : "YES") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
