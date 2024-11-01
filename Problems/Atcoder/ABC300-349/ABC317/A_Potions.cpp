#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    cout << ranges::lower_bound(vec, k - x) - vec.begin() + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}