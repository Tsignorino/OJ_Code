#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    开数组记录 108 ms
    set       936 ms
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    constexpr int MX = 1 << 8;

    vector<int> cnt(MX);
    cnt[0] = 1;
    int ans = 0, res = 0;
    for (int& v : vec) {
        res ^= v;
        for (int pre = 0; pre < MX; ++pre) {
            if (cnt[pre] == 1) {
                ans = max(ans, res ^ pre);
            }
        }
        cnt[res] = 1;
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