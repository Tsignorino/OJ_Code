#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

// Alice 移除最大的元素 0 ~ k 个
// Bob 将最大的 min(len(nums), x) 个元素标记

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end());

    vector<int> preSum(n + 1);
    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    // int r = n;
    int ans = INT_MIN;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, preSum[max(n - i - x, 0)] * 2 - preSum[n - i]);

        // int cnt = min(r - i, x);
        // int sum = 0;
        // for (int j = n - i - 1; j >= 0; --j) {
        //     if (cnt > 0) {
        //         sum -= nums[j];
        //         cnt--;
        //     } else {
        //         sum += nums[j];
        //     }
        // }
        // ans = max(ans, sum);
    }

    cout << ans << "\n";
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
