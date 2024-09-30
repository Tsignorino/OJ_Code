#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

// 反悔贪心：
// tot - cj + pj + ci < tot + pi  <==> pj - cj < pi - ci

void solve() {
    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<int> p(n), c(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> P, C;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
        P.emplace(p[i], i);
        C.emplace(c[i], i);
    }

    priority_queue<int, vector<int>, greater<>> diff;
    for (int i = 0; i < k; ++i) {
        diff.emplace(0);
    }

    vector<int> ok(n); // 标记是否购买
    int ans = 0;
    while (!P.empty()) {
        pair<int, int> x1 = P.top(), x2 = C.top();
        if (ok[x1.second]) {
            P.pop();
            continue;
        }
        if (ok[x2.second]) {
            C.pop();
            continue;
        }

        if (diff.top() <= x1.first - x2.first) {
            m -= x2.first + diff.top();
            diff.pop();
            C.pop();

            int j = x2.second;
            ok[j] = 1;
            diff.emplace(p[j] - c[j]);
        } else {
            m -= x1.first;
            P.pop();
            ok[x1.second] = 1;
        }

        if (m < 0) {
            break;
        }
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
