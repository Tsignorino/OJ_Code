#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    // 把单调子数组中间的值去掉即可
    vector<int> res {vec[0]};
    for (int i = 1; i < n - 1; ++i) {
        if ((vec[i] - vec[i - 1]) * 1ll * (vec[i] - vec[i + 1]) < 0) {
            continue;
        }
        res.emplace_back(vec[i]);
    }
    res.emplace_back(vec[n - 1]);

    cout << res.size() << "\n";
    for (int& v : res) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
