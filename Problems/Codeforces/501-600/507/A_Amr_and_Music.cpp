// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int i, int j) { return a[i] < a[j]; });

    vector<int> ans;
    for (int i : idx) {
        if (k >= a[i]) {
            ans.push_back(i);
            k -= a[i];
        } else {
            break;
        }
    }
    cout << ssize(ans) << "\n";
    for (int& v : ans) {
        cout << v + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}