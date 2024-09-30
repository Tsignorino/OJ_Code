#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 定义数组及其边界状态
    int f[2][n]; // f[0][n] 表示不删除元素，f[1][n] 表示已经删除一个元素
    memset(f, 0, sizeof(f));
    f[0][0] = f[0][1] = f[1][0] = f[1][1] = 1;
    if (nums[1] > nums[0]) {
        f[0][1] = 2;
    }

    for (int i = 2; i < n; ++i) {
        if (nums[i - 2] < nums[i]) { // 把 nums[i-1] 删掉的情况
            f[1][i] = max(f[1][i], f[0][i - 2] + 1);
        }

        if (nums[i - 1] < nums[i]) { // 正常状态转移
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
