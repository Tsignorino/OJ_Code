#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    // vector<int> vec(n);
    // iota(vec.begin(), vec.end(), 1);
    // reverse(vec.begin(), vec.end());

    // if (n & 1) {
    //     swap(vec[n / 2], vec[n / 2 + 1]);
    // }

    // for (int i = 0; i < n; ++i) {
    //     cout << vec[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << (i + 1) % n + 1 << " ";
    }
    cout << "\n";
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
