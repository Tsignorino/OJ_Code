#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> ans(n * 2);
    for (int i = 0; i < n / 2; ++i) {
        ans[i] = i * 2 + 1;
        ans[n - 1 - i] = i * 2 + 1;
        ans[n + i] = (i + 1) * 2;
        ans[2 * n - 2 - i] = (i + 1) * 2;
    }

    replace(ans.begin(), ans.end(), 0, n);
    for (int& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}