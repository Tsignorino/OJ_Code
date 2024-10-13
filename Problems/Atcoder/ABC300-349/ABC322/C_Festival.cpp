#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(m);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 1; i <= n; ++i) {
        cout << *ranges::lower_bound(vec, i) - i << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}