#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) { return vec[i] < vec[j]; });

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[id[i]];
    }

    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + vec[id[i]];
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        // ll left = (vec[id[i]] * i) - pre[i] + i;
        // ll right = suf[i] - (vec[id[i]] * (n - i)) + n - i;
        // ans[id[i]] = left + right;
        ans[id[i]] = (vec[id[i]] * (2 * i - n)) - pre[i] + suf[i] + n;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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