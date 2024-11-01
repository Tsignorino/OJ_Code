#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int cnt[5] {}, num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        cnt[num]++;
    }

    int ans = cnt[4] + cnt[3] + (cnt[2] + 1) / 2;
    cnt[1] -= 2 * (cnt[2] & 1) + cnt[3];
    ans += cnt[1] > 0 ? (cnt[1] + 3) / 4 : 0;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
