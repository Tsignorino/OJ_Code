#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (ll& v : vec) { // ! 后续的 partial_sum
        cin >> v;
    }

    string s;
    cin >> s;

    vector<ll> pre(n + 1);
    partial_sum(vec.begin(), vec.end(), pre.begin() + 1);

    ll ans = 0;
    int l = 0, r = n - 1;
    while (true) {
        while (l < r && s[l] != 'L') {
            l++;
        }
        while (l < r && s[r] != 'R') {
            r--;
        }
        if (l >= r) {
            break;
        }
        ans += pre[r + 1] - pre[l];
        l++, r--;
    }
    cout << ans << "\n";
}

void solve2() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    string s;
    cin >> s;

    vector<int> L, R;
    for (int i = 0; i < s.size(); ++i) {
        (s[i] == 'L' ? L : R).emplace_back(i);
    }

    if (L.empty() || R.empty()) {
        cout << 0 << "\n";
        return;
    }

    int p = 0, q = R.size() - 1;
    ll sum = 0;
    while (L[p] < R[q]) {
        sum += pre[R[q] + 1] - pre[L[p]];
        p++, q--;
        if (p >= L.size() || q < 0) {
            break;
        }
    }
    cout << sum << "\n";
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