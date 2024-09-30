#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    二分答案
*/
void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        int idx = 0;
        for (int i = 0; i < 3 && idx < n; ++i) {
            idx = upper_bound(vec.begin(), vec.end(), vec[idx] + mid * 2) - vec.begin();
        }

        (idx == n ? r : l) = mid;
    }
    cout << r << "\n";
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
