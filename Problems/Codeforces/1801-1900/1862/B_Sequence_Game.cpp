#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (i && a.back() > num) {
            a.emplace_back(1);
        }
        a.emplace_back(num);
    }

    int m = a.size();
    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        cout << a[i] << " \n"[i == m - 1];
    }
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
