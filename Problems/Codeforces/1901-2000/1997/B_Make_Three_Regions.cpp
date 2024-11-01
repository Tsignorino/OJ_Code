#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> vec(2);
    for (int i = 0; i < 2; ++i) {
        cin >> vec[i];
    }

    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i].substr(j, 3) == "..." && vec[i ^ 1].substr(j, 3) == "x.x") {
                ans++;
            }
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