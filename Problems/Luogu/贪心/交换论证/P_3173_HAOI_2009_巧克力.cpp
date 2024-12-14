#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    同 LeetCode contest 406 t4
*/

void solve() {
    int n, m;
    cin >> n >> m;
    n--, m--;

    vector<pair<int, int>> vec;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        vec.emplace_back(v, 0);
        sum1 += v;
    }
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        vec.emplace_back(v, 1);
        sum2 += v;
    }

    ranges::sort(vec, greater<>());

    ll cost = 0;
    for (auto& [v, c] : vec) {
        if (c == 0) {
            cost += sum2 + v;
            sum1 -= v;
        } else {
            cost += sum1 + v;
            sum2 -= v;
        }
    }
    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}