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
        int val;
        cin >> val;
        vec.emplace_back(val, 0);
        sum1 += val;
    }
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        vec.emplace_back(val, 1);
        sum2 += val;
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