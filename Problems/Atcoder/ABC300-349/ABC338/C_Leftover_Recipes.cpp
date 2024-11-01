#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }
    vector<int> b(n);
    for (int& v : b) {
        cin >> v;
    }

    int ans = 0;
    int cnt = 0;
    while (ranges::min(vec) >= 0) {
        int mx = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (b[i]) {
                mx = min(mx, vec[i] / b[i]);
            }
        }
        ans = max(ans, mx + cnt);
        cnt++;
        for (int i = 0; i < n; ++i) {
            vec[i] -= a[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}