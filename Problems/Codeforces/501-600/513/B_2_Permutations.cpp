#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    k--;

    int l = 0, r = n - 1;
    vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
        if (k >> (n - 1 - i) & 1) { // 后半部分
            ans[r--] = i;
        } else {
            ans[l++] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}