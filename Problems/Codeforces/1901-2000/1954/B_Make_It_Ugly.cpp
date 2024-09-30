#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int num = vec[0], cnt = 0, ans = n;
    for (int i = 0; i < n; ++i) {
        if (vec[i] == num) {
            cnt++;
        } else {
            ans = min(ans, cnt);
            cnt = 0;
        }
    }
    ans = min(ans, cnt);
    cout << (ans == n ? -1 : ans) << "\n";
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
