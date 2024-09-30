#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    ll k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    ranges::sort(a, greater<>());
    ranges::sort(b, greater<>());

    auto func = [&](ll k, vector<int>& vec) {
        ll pre = 0;
        for (int i = 0; i < n; ++i) {
            pre += vec[i];
            if (pre > k) {
                return i + 1;
            }
        }
        return n;
    };

    cout << min(func(k1, a), func(k2, b)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}