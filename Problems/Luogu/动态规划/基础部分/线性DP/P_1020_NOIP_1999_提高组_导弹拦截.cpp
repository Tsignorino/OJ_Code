#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int val;
    vector<int> vec;
    while (cin >> val) {
        vec.emplace_back(val);
    }

    int n = vec.size();
    vector<int> f;
    for (int i = 0; i < n; ++i) {
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

    solve();

    return 0;
}
