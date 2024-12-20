#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    i64 sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        cnt += a[i] == 1;
    }

    if (sum >= cnt + n && n > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
