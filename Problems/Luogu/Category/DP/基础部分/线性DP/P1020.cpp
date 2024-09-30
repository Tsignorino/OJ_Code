#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    导弹拦截：最长不上升子序列 nlogn
*/

void solve() {
    // ! 调试用
    // int n;
    // cin >> n;
    // vector<int> vec(n);
    // for (int& v : vec) {
    //     cin >> v;
    // }

    int val;
    vector<int> vec;
    while (cin >> val) {
        vec.emplace_back(val);
    }

    // for (auto& v : vec) {
    //     cout << v << " ";
    // }

    // 最长不上升子序列
    int n = vec.size();
    vector<int> f; // f[i] 表示当前位置的最小值
    // vector<int> f(n, 1); // f[i] 表示以 ai 结束的最长不上升子序列的长度
    for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < i; ++j) {
        //     if (vec[j] >= vec[i]) {
        //         f[i] = max(f[i], f[j] + 1);
        //     }
        // }

        // 第一个小于当前值的位置
        int l = -1, r = f.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            (f[mid] >= vec[i] ? l : r) = mid;
        }
        if (r == f.size()) {
            f.emplace_back(vec[i]);
        } else {
            f[r] = vec[i];
        }
    }
    // cout << ranges::max(f) << "\n"; //! BF: 第 n 个数不一定是最长单调不升子序列的最后一项
    cout << f.size() << "\n";

    // 拦截系统的高度按从小到大排序
    vector<int> g(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = cnt + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            (g[mid] < vec[i] ? l : r) = mid;
        }

        cnt = max(cnt, r);
        g[r] = vec[i];
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
