#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    multiset<int> a;
    for (int i = 0; i < n - 1; ++i) {
        int v;
        cin >> v;
        a.emplace(v);
    }

    ranges::sort(vec, greater<>());

    vector<int> res;
    for (int& v : vec) {
        auto iter = a.lower_bound(v);
        if (iter == a.end()) {
            res.emplace_back(v);
        } else {
            a.erase(iter);
        }
    }

    if (res.size() > 1) {
        cout << -1 << "\n";
    } else {
        cout << res.back() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}