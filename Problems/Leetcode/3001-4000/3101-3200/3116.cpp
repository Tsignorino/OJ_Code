#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto check = [&](ll m) -> bool {
            ll cnt = 0;
            for (int i = 1; i < (1 << n); ++i) {
                ll lcm_ = 1;
                for (int j = 0; j < n; ++j) {
                    if (i >> j & 1) {
                        lcm_ = lcm(lcm_, coins[j]);
                        if (lcm_ > m) { // !
                            break;
                        }
                    }
                }
                cnt += __popcount(i) % 2 ? m / lcm_ : -m / lcm_;
            }
            return cnt >= k;
        };

        ll l = k - 1, r = ranges::min(coins) * 1ll * k;
        while (l + 1 < r) {
            ll mid = l + (r - l) / 2;
            (check(mid) ? r : l) = mid;
        }
        return r;
    }
};

// 1201