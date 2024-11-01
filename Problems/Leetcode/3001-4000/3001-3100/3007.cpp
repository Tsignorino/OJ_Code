#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;

public:
    long long findMaximumNumber(long long k, int x) {
        auto check = [&](long long num) {
            ll res = 0;
            int i = x - 1;
            for (ll n = num >> i; n; n >>= x, i += x) {
                res += (n / 2) << i;
                if (n & 1) {
                    ll mask = (1ll << i) - 1;
                    res += (num & mask) + 1;
                }
            }
            return res <= k;
            /*
                int m = __lg(num) + 1;
                vector memo(m, vector<ll>(m + 1, -1));
                auto dfs = [&](auto&& self, int i, int cnt, bool isLimit) -> ll {
                    if (i < 0) {
                        return cnt;
                    }

                    ll& res = memo[i][cnt];
                    if (!isLimit && res >= 0) {
                        return res;
                    }

                    int up = isLimit ? num >> i & 1 : 1;
                    ll ans = 0;
                    for (int d = 0; d <= up; ++d) {
                        ans += self(self, i - 1, cnt + (d == 1 && (i + 1) % x == 0), isLimit && d == up);
                    }
                    if (!isLimit) {
                        res = ans;
                    }
                    return ans;
                };
                return dfs(dfs, m - 1, 0, true) <= k;
            */
        };

        ll l = 0, r = (k + 1) << x;
        while (l + 1 < r) {
            ll mid = l + (r - l) / 2;
            (check(mid) ? l : r) = mid;
        }
        return l;
    }
};

int main() {
    Solution sol;

    return 0;
}