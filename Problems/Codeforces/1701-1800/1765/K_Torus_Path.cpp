#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    手玩一下，如果想把副对角线都走一遍是到不了终点的，最好的情况就是元素和减去副对角线最小值
*/

void solve() {
    int n;
    cin >> n;

    int mn = INT_MAX;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v;
            cin >> v;
            sum += v;
            if (i + j == n - 1) {
                mn = min(mn, v);
            }
        }
    }
    cout << sum - mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}