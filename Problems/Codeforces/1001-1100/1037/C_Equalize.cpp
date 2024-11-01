#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int ans = 0, pre = n;
    for (int i = 0; i < n; ++i) {
        if (a[i] ^ b[i]) {
            if (i - pre == 1 && a[i] ^ a[pre]) {
                continue;
            }
            ans++;
            pre = i;
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