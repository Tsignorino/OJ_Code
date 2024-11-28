// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for (int& v : a) {
        cin >> v;
        mp[v]++;
    }

    vector<int> vec;
    for (auto& [v, c] : mp) {
        for (int i = 0; i < c / 2; ++i) {
            vec.emplace_back(v);
        }
    }

    if (vec.size() < 4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        int n = vec.size();
        int a = vec[0], b = vec[1], c = vec[n - 2], d = vec[n - 1];
        cout << format("{} {} {} {} {} {} {} {}\n", a, b, a, d, c, b, c, d);
    }
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