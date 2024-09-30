#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int nums[n * 2];
    for (int i = 0; i < n * 2; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums + n * 2);

    cout << nums[n] - nums[n - 1] << "\n";
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
