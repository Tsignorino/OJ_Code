#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector f(2, vector<int>(n)); // f[0][n] 表示不删除元素，f[1][n] 表示已经删除一个元素
    f[0][0] = f[0][1] = f[1][0] = f[1][1] = 1;
    if (vec[1] > vec[0]) {
        f[0][1] = 2;
    }
    for (int i = 2; i < n; ++i) {
        if (vec[i - 2] < vec[i]) { // 把 vec[i-1] 删掉的情况
            f[1][i] = max(f[1][i], f[0][i - 2] + 1);
        }
        if (vec[i - 1] < vec[i]) { // 正常状态转移
            f[0][i] = max(f[0][i], f[0][i - 1] + 1);
            f[1][i] = max(f[1][i], f[1][i - 1] + 1);
        } else {
            f[0][i] = max(f[0][i], 1);
            f[1][i] = max(f[1][i], 1);
        }
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, max(f[0][i], f[1][i]));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
