#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

// 记忆化搜索
void solve() {
    int d, n;
    cin >> d >> n;
    vector vec(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }

    ranges::sort(vec);
    vec.insert(vec.begin(), vector {0, 0, 0});
    vec.emplace_back(vector {INT_MAX / 2, 0, 0});

    int mx = 0, mn = INT_MAX / 2, ok = 0;
    map<int, map<int, map<int, int>>> memo;
    function<void(int, int, int)> dfs = [&](int i, int h, int left) -> void {
        int& res = memo[i][h][left];
        if (res != 0) {
            return;
        }
        res = 1;

        if (i > n + 1) {
            return;
        }

        if (left >= vec[i][0] - vec[i - 1][0]) {
            left -= vec[i][0] - vec[i - 1][0];
        } else {
            mx = max(mx, vec[i - 1][0] + left);
            return;
        }

        if (h + vec[i][2] >= d) {
            ok = 1;
            mn = min(mn, vec[i][0]);
            return;
        }

        dfs(i + 1, h, left + vec[i][1]);
        dfs(i + 1, h + vec[i][2], left);
        return;
    };

    dfs(1, 0, 10);
    if (ok) {
        cout << mn << "\n";
    } else {
        cout << mx << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}