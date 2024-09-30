#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> vec(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        vec[i] = s[i] == s[i + 1];
    }

    vector<ll> pre(n);
    for (int i = 0; i < n - 1; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << pre[r] - pre[l] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}