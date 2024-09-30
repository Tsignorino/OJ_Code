#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    饥饿的奶牛：按右端点排序（根据二分过程）
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }

    ranges::sort(vec, [&](const auto& p, const auto& q) { return p[1] < q[1] || p[1] == q[1] && p[0] < q[0]; });

    auto find = [&](int x) -> int {
        int l = 0, r = x;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (vec[mid][1] < vec[x][0]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    };

    vector<ll> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        int j = find(i);
        f[i] = max(f[i - 1], f[j] + vec[i][1] - vec[i][0] + 1);
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}