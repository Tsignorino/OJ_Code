#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1), idx(n + 1);
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        cnt[num]++;
        idx[num] = i + 1;
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 1) {
            ans = idx[i];
            break;
        }
    }

    cout << ans << "\n";
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
