#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr double eps = 1e-6;

/*
    二分 + 前缀和 + 单调队列
*/

void solve() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    auto check = [&](auto x) {
        vector<double> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + vec[i] - x;
        }

        deque<int> q;
        for (int i = s, j = 0; i <= n; ++i, ++j) {
            while (!q.empty() && pre[q.back()] > pre[j]) {
                q.pop_back();
            }
            q.emplace_back(j);
            while (q.front() < i - t) {
                q.pop_front();
            }
            if (pre[i] - pre[q.front()] >= 0) {
                return true;
            }
        }
        return false;
    };

    double l = 0, r = 1e9;
    while (l + eps < r) {
        auto mid = l + (r - l) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}