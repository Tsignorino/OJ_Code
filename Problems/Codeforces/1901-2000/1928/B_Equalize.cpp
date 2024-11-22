#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

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