#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int minV = 1e9, ans = -1;
    for (int i = k; i < n; ++i) { // 从当前选择的子数组中点出发，左右扩散 k+1 个点
        if (vec[i] - vec[i - k] < minV) {
            minV = vec[i] - vec[i - k];
            ans = (vec[i] + vec[i - k]) / 2;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
