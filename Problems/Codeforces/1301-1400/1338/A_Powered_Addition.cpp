#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    int ans = 0, maxV = INT_MIN;
    for (int& v : vec) {
        cin >> v;
        maxV = max(maxV, v);
        if (maxV > v) {
            ans = max(ans, std::__lg(maxV - v) + 1);
        }
    }
    cout << ans << "\n";
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
