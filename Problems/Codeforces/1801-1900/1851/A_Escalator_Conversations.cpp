#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    
    vector<int> vec(n);
    int cnt = 0;
    for (int& val : vec) {
        cin >> val;

        int res = abs(h - val);
        cnt += res && res % k == 0 && res / k < m;
    }

    cout << cnt << "\n";
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
