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

    int sum = accumulate(vec.begin(), vec.end(), 0);
    int mx = ranges::max(vec);
    int mn = ranges::min(vec);

    cout << (mn + mx) * (mx - mn + 1) / 2 - sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}