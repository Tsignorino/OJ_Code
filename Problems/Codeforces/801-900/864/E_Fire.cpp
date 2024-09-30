#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

struct item {
    int t, d, p, id;
};

void solve() {
    int n;
    cin >> n;
    vector<item> a(n);
    int id = 0;
    for (auto& v : a) {
        cin >> v.t >> v.d >> v.p;
        v.id = ++id;
    }

    // f[i] 表示到 i 时刻取出来多少价值
    // f[i] = max(f[i], f[i-t[j]] + p[j])  (i - t[j] <= d[j])
    ranges::sort(a, [&](const item& p, const item& q) -> bool { return p.d < q.d; });

    int m = a[n - 1].d;
    vector<int> f(m);
    vector<vector<int>> pa(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        int t = a[i].t;
        for (int j = a[i].d - 1; j >= t; --j) {
            if (f[j] < f[j - t] + a[i].p) {
                f[j] = f[j - t] + a[i].p;

                pa[i][j] = j - t;
            }
        }
    }

    id = 0;
    for (int i = 0; i < f.size(); ++i) {
        if (f[i] > f[id]) {
            id = i;
        }
    }
    cout << f[id] << "\n";

    vector<int> ans;
    for (int i = n - 1, j = id; i >= 0; --i) {
        if (pa[i][j] != -1) {
            ans.emplace_back(a[i].id);
            j = pa[i][j];
        }
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
