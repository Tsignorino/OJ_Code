#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> c(n);
    for (int& v : c) {
        cin >> v;
    }

    cout << find(c.begin(), c.end(), a + b) - c.begin() + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}