#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

class Fenwick {
private:
    vector<int> f;
    int Op(int a, int b) { return a + b; } // add, max

public:
    explicit Fenwick(int n) : f(n + 1, 0) {}
    explicit Fenwick(vector<int>& vec) : f(vec.size() + 1) {
        for (int i = 0; i < vec.size(); ++i) {
            update(i + 1, vec[i]);
        }
    }

    void update(int id, int val) { // a[i] += val, 1<=i<=n
        for (int i = id; i <= f.size(); i += i & -i) {
            f[i] = Op(f[i], val);
        }
    }

    int preSum(int id) { // [1, id]
        int res = 0;
        for (int i = id; i > 0; i &= i - 1) { // i -= i & -i
            res += f[i];
        }
        return res;
    }

    int rangeSum(int l, int r) { return preSum(r) - preSum(l - 1); } // [l, r]
};
/*
   1
  2 3
 4   5

    寻找比 x 强的下属 = 添加下属之后比 x 强的 - 添加下属之前就比 x 强的
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int val;
        cin >> val;
        g[val].emplace_back(i);
    }

    vector<int> tmp(vec);
    ranges::sort(tmp);
    for (int& v : vec) {
        v = ranges::lower_bound(tmp, v) - tmp.begin();
    }

    vector<int> res(n + 1);
    Fenwick f(n + 1);
    function<void(int)> dfs = [&](int x) -> void {
        res[x] -= f.preSum(n) - f.preSum(vec[x]);
        for (int& v : g[x]) {
            dfs(v);
        }
        res[x] += f.preSum(n) - f.preSum(vec[x]);
        f.update(vec[x], 1);
    };
    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}