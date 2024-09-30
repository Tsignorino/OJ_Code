#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/79664/F
*/

void solve() {
    const int n = 5;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    for (int i = 0; i < n - 1; ++i) {
        vec[n - 1] += max(vec[i] - 1, 0);
    }
    cout << vec[n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}