#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int l, s, t, m;
    cin >> l >> s >> t >> m;

    int stone[101];
    for (int i = 1; i <= m; i++) {
        cin >> stone[i];
    }
    sort(stone, stone + m + 2);

    bool bridge[100001]; // 存储离散化之后桥上石子的分布情况
    int id = 0;
    for (int i = 1; i <= m + 1; ++i) {
        if (stone[i] - stone[i - 1] <= t * s) {
            id += stone[i] - stone[i - 1];
        } else {
            id += (stone[i] - stone[i - 1]) % t + t;
        }
        bridge[id] = true;
    }

    vector<int> sum(10001, INT_MAX / 2);
    sum[0] = 0;
    for (int i = 1; i <= id + t; ++i) {
        for (int j = s; j <= t; ++j) {
            if (i >= j) {
                sum[i] = min(sum[i], sum[i - j] + bridge[i]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = id; i <= id + t; ++i) {
        ans = min(ans, sum[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
