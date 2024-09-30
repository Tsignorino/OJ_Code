#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        vec[val] = i;
    }

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        cnt[(vec[val] - i + n) % n]++;
    }
    cout << ranges::max(cnt) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
