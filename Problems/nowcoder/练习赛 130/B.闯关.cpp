#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    ll h, l, r;
    cin >> n >> k >> h >> l >> r;

    if (r * (k - 1) + h <= 0 || l * k + h > 0) {
        cout << "impossible\n";
        return;
    }

    vector<int> ans(n, r);
    ll sum = r * k + h;
    for (int i = k - 1; i >= 0; --i) {
        if (sum > 0) {
            int d = min(sum, r - l);
            sum -= d;
            ans[i] -= d;
        } else {
            break;
        }
    }

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