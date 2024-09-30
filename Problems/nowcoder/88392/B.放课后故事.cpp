#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88392/B
*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);

    cout << min(sum / k, m + 1ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}