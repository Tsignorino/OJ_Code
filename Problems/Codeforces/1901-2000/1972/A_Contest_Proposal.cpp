#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }
    vector<int> b(n);
    for (int& v : b) {
        cin >> v;
    }

    int cnt = 0;
    for (int i = n - 1, j = n - 1; i >= 0; --i) {
        a[i] > b[j] ? cnt++ : j--;
    }
    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
