#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    sort(vec.begin(), vec.end(), greater<>());

    int cost = 0, cnt = 0;
    for (int i = 1; i < n; ++i) {
        int d = vec[i - 1] - vec[i];
        if (cost + d * i < k) {
            cost += d * i;
            continue;
        }

        // 细分高度
        d -= (k - cost) / i;
        cnt += 1 + d / (k / i);
        cost = d % (k / i) * i;
    }

    cout << cnt + (cost > 0) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
