#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int minV = 1e9, id = 0; // 考虑数组所有元素相等的情况
    for (int i = 0; i < n; ++i) {
        int& v = vec[i];
        cin >> v;

        if (v < minV) { // 寻找第一个最小值
            minV = v;
            id = i;
        }
    }

    for (int i = id + 1; i < n; ++i) {
        if (vec[i] < vec[i - 1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << id << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
