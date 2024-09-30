#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    // 要解决无重复方案，可以添加规定，后续数字较大
    int cnt = 0;
    function<void(int, int, int)> dfs = [&](int last, int sum, int cur) -> void {
        if (cur == k) {
            if (sum == n) {
                cnt++;
            }
            return;
        }
        for (int i = last; sum + i * (k - cur) <= n; i++) { // 剪枝，只用枚举到 sum + i * (k-cur) <= n 为止
            dfs(i, sum + i, cur + 1);
        }
    };

    dfs(1, 0, 0);
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
