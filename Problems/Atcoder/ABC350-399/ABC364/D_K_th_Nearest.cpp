#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ranges::sort(vec);

    while (q--) {
        int v, k;
        cin >> v >> k;

        int l = -1, r = 1e9;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;

            int cnt = ranges::upper_bound(vec, v + mid) - ranges::lower_bound(vec, v - mid);
            (cnt >= k ? r : l) = mid;
        }
        cout << r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}