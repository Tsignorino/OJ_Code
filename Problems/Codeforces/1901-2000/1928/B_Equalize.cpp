#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    ranges::sort(nums);
    auto iter = unique(nums.begin(), nums.end());
    nums.erase(iter, nums.end());
    // nums.resize(iter - nums.begin());

    int ans = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
        while (nums[r] - nums[l] >= n) {
            l++;
        }
        ans = max(ans, r - l + 1);
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
