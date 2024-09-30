#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 998'244'353;
constexpr int MX = 5000;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end());

    vector<vector<ll>> cnt(2, vector<ll>(MX << 1 | 1));
    cnt[0][0] = 1;
    int cur = 0;
    for (int& num : nums) {
        cur ^= 1;
        for (int i = 0; i <= MX << 1; ++i) {
            cnt[cur][i] = cnt[cur ^ 1][i];
        }
        for (int i = num; i <= MX << 1; ++i) {
            cnt[cur][i] = (cnt[cur][i] + cnt[cur ^ 1][i - num]) % mod;
        }
    }

    vector<ll>& vec = cnt[cur];
    ll res = 0;
    for (int& num : nums) {
        for (int i = 0; i < num; ++i) {
            res = (res + vec[i] * (num - (num + i + 1) / 2)) % mod;
        }
    }

    for (int i = 1; i <= MX; ++i) {
        res = (res + i * (vec[i * 2] + vec[i * 2 - 1])) % mod;
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
