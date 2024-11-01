#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int m;
    cin >> m;

    vector<int> ans;
    while (m) {
        int v = log(m) / log(3);
        m -= pow(3, v);
        ans.emplace_back(v);
    }

    cout << ans.size() << "\n";
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