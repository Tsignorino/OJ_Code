#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        if (vec[i] == k) {
            p = i;
        }
    }

    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (vec[mid] <= k ? l : r) = mid;
    }

    cout << format("1\n{} {}\n", p + 1, l + 1);
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
