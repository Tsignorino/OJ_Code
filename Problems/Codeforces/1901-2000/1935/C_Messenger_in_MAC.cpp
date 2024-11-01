#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

struct Node {
    int a, b;
};

void solve() {
    int n, l;
    cin >> n >> l;
    vector<Node> vec(n);
    for (auto& [a, b] : vec) {
        cin >> a >> b;
    }

    ranges::sort(vec, [&](const Node& p, const Node& q) { return p.b < q.b; });

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vec[i].a <= l) {
            ans = max(ans, 1ll);
        }

        priority_queue<int> q;
        ll sum = 0;
        for (int j = i - 1; j >= 0 && vec[i].a + vec[i].b - vec[j].b < l; --j) {
            q.emplace(vec[j].a);
            sum += vec[j].a;
            while (!q.empty() && vec[i].a + vec[i].b - vec[j].b + sum > l) {
                sum -= q.top();
                q.pop();
            }
            ans = max(ans, ll(q.size() + 1));
        }
    }
    cout << ans << "\n";

    //* DP:
    // 前 j 项中选 i 个，且第 j 个必选
    // 即求 sum(a) + b[j] - b[k] （b[k] 是第一个选的数）
    // 记 f[i][j] 表示 sum(a) - b[k] 的最小值
    //
    // vector f(n, vector<ll>(n, LLONG_MAX / 2));
    // ll ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     f[0][i] = vec[i].a - vec[i].b;
    //     if (vec[i].a <= l) {
    //         ans = 1;
    //     }
    // }
    // for (int i = 1; i < n; ++i) {
    //     ll mn = f[i - 1][i - 1];
    //     for (int j = i; j < n; ++j) {
    //         f[i][j] = mn + vec[j].a;
    //         if (f[i][j] + vec[j].b <= l) {
    //             ans = i + 1;
    //         }
    //         mn = min(mn, f[i - 1][j]);
    //     }
    // }
    // cout << ans << "\n";
    //
    // 优化：
    // vector<ll> f(n);
    // ll ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     f[i] = vec[i].a - vec[i].b;
    //     if (vec[i].a <= l) {
    //         ans = 1;
    //     }
    // }
    // for (int i = 1; i < n; ++i) {
    //     ll mn = f[i - 1];
    //     for (int j = i; j < n; ++j) {
    //         ll tmp = f[j];
    //         f[j] = mn + vec[j].a;
    //         if (f[j] + vec[j].b <= l) {
    //             ans = i + 1;
    //         }
    //         mn = min(mn, tmp);
    //     }
    // }
    // cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}