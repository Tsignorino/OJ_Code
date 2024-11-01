#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
    using ll = long long;

public:
    /*
        二分
    */
    long long minNumberOfSeconds(int h, vector<int>& t) {
        auto check = [&](auto x) {
            ll tot = 0;
            for (int v : t) {
                tot += max(0, int(sqrt(8 * x / v + 1) - 1) / 2);
                if (tot >= h) {
                    return true;
                }
            }
            return false;
        };

        ll l = 0, r = 1e17;
        while (l + 1 < r) {
            auto mid = l + (r - l) / 2;

            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }

    /*
        最小堆
    */
    long long _minNumberOfSeconds(int h, vector<int>& t) {
        priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<>> pq;
        for (int v : t) {
            pq.emplace(v, v, v);
        }

        ll ans = 0;
        while (h--) {
            auto [nxt, delta, base] = pq.top();
            pq.pop();

            ans = max(ans, nxt);
            pq.emplace(nxt + delta + base, delta + base, base);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}