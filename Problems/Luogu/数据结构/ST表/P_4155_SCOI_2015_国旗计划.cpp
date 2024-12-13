#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

struct Guard {
    int id, l, r;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Guard> vec(n * 2);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (r < l) { // 延伸
            r += m;
        }
        vec[i] = Guard(i, l, r);
        vec[i + n] = Guard(i, l + m, r + m); // 复制
    }

    ranges::sort(vec, [&](const Guard& a, const Guard& b) { return a.l < b.l; });

    // 倍增，预处理（从一名战士开始，直到另一名战士的左端点大于该战士的右端点）
    int len = __lg(n);
    vector<vector<int>> path(n * 2, vector<int>(len + 1));
    for (int i = 0, p = i; i < n * 2; ++i) {
        while (p < 2 * n && vec[p].l <= vec[i].r) {
            p++;
        }
        path[i][0] = p - 1;
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            path[j][i] = path[path[j][i - 1]][i - 1];
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int end = vec[i + n].l;
        int cur = i, res = 1;
        // 从后往前找跳跃的有效值
        for (int j = len; j >= 0; --j) {
            int& next = path[cur][j];
            if (next && vec[next].r < end) {
                res += 1 << j;
                cur = next;
            }
        }
        ans[vec[i].id] = res + 1; // 注意编号
    }

    for (int& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
